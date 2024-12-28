#ifndef QPrabhupada_H
#define QPrabhupada_H

#include <QtCore>
#include <QtSql>
#include <QtGui>
#include <map>
#include <memory>

template < class TValueType >
class QEmitValue : public QObject
{
  CS_OBJECT( QEmitValue )
  public:
    using inherited = QObject;
    TValueType m_Value;
    bool m_NeedMainWork = true;
    int m_Stop = 0;
    QEmitValue( QObject *parent = nullptr )
      : inherited( parent )
    {
    };
    QEmitValue( const QEmitValue& A )
      : inherited( A.parent() )
      , m_Value       ( A.m_Value )
      , m_NeedMainWork( A.m_NeedMainWork )
      , m_Stop        ( A.m_Stop )
    {
    };
    QEmitValue( QEmitValue&& A )
      : inherited( A.parent() )
      , m_Value       ( std::move( A.m_Value ) )
      , m_NeedMainWork( std::move( A.m_NeedMainWork ) )
      , m_Stop        ( std::move( A.m_Stop ) )
    {
    };
    QEmitValue& operator = ( const QEmitValue& A )
    {
      m_Value        = A.m_Value;
      m_NeedMainWork = A.m_NeedMainWork;
      m_Stop         = A.m_Stop;

      return *this;
    };
    QEmitValue& operator = ( QEmitValue&& A )
    {
      m_Value        = std::move( A.m_Value );
      m_NeedMainWork = std::move( A.m_NeedMainWork );
      m_Stop         = std::move( A.m_Stop );

      return *this;
    };
    bool operator == ( const QEmitValue& A )
    {
      return m_Value        == A.m_Value &&
             m_NeedMainWork == A.m_NeedMainWork &&
             m_Stop         == A.m_Stop;
    };
    bool operator != ( const QEmitValue& A )
    {
      return m_Value        != A.m_Value ||
             m_NeedMainWork != A.m_NeedMainWork ||
             m_Stop         != A.m_Stop;
    };
    QEmitValue( TValueType Value, QObject *parent = nullptr )
      : inherited( parent )
      , m_Value( Value ) {};
    virtual ~QEmitValue() {};

    CS_SIGNAL_1( Public, void SignalValueChanged( TValueType Value ) )
    CS_SIGNAL_2( SignalValueChanged, Value )

    void SetValue( TValueType Value )
    {
      if ( m_Stop == 0 && m_Value != Value ) {
        m_Value = Value;
        m_NeedMainWork = true;
        emit SignalValueChanged( m_Value );
      }
    };
    virtual void LoadFromStream( QDataStream &ST )
    {
      TValueType N;
      ST >> N;
      SetValue( N );
    };
    virtual void SaveToStream( QDataStream &ST )
    {
      ST << m_Value;
    };
    inline void EmitValueChanged( bool ANeedResetMainWork = false )
    {
      if ( ANeedResetMainWork ) {
        m_NeedMainWork = true;
      }
      emit SignalValueChanged( m_Value );
      m_NeedMainWork = false;
    };
  protected:
};

using QEmitInt  = QEmitValue< int >;
using QEmitBool = QEmitValue< bool >;

enum class QStorageKind : quint8 { File, DB, Memory };

class QMapMemoryStorage : public std::map< QString, std::unique_ptr< QDataStream > >
{
  private:
    using inherited = std::map< QString, std::unique_ptr< QDataStream > >;
  public:
    QMapMemoryStorage();
    ~QMapMemoryStorage();
    void LoadFromStream( QDataStream &ST );
    void SaveToStream(   QDataStream &ST );
};

class QStorager
{
  public:
    QStorager();
    virtual ~QStorager();
    virtual void LoadFromStream( void *AObject, QDataStream &ST ) = 0;
    virtual void SaveToStream(   void *AObject, QDataStream &ST ) = 0;
};

class QStorage
{
  protected:
    QFile *m_File = nullptr;
    QSaveFile *m_SaveFile = nullptr;
    QDataStream *m_Stream = nullptr;
    QString m_FileName;
    QByteArray *m_ByteArray;
    QMapMemoryStorage m_MapMemoryStorage;
    void PrepareFileName( void* O, QStorageKind AStorageKind, const QString& AKeyStorage );
    bool BeginLoad( QStorageKind AStorageKind );
    void EndLoad( QStorageKind AStorageKind );
    void BeginSave( QStorageKind AStorageKind );
    void EndSave( QStorageKind AStorageKind );
    virtual bool BeginLoadDB() { return false; };
    virtual void EndLoadDB() {};
    virtual void BeginSaveDB() {};
    virtual void EndSaveDB() {};
  public:
    QStorage();
    QStorage( QStorage&& A );
    QStorage( const QStorage& A );
    virtual ~QStorage();
    QStorage& operator = ( const QStorage& A );
    QStorage& operator = ( QStorage&& A );

    bool m_Enabled = true;
    qint8 m_Version = 0;

    void setEnabled( bool Value );
    virtual QString PrefixKeyStorage() { return ""; };
    QString KeyStorage( QObject *O, QStorageKind AStorageKind );
    virtual void ResetSettings() {};

    static int MaxHistoryComboBox;
    static void PrepareHistoryComboBox( QComboBox *CB, int MaxCount = MaxHistoryComboBox );
    static void LoadFromStream( QComboBox *CB, QDataStream &ST );
    static void SaveToStream( QComboBox *CB, QDataStream &ST );

    template< class TMap, class TKey, class TValue >
    static void LoadMap( TMap &MP, QDataStream &ST )
    {
      // 1
      std::size_t L;
      ST >> L;
      // 2
      TKey AKey;
      TValue AValue;
      for ( std::size_t I = 0; I < L; ++I ) {
        ST >> AKey;
        ST >> AValue;
        MP[ AKey ] = AValue;
      }
    }

    template< class TMap >
    static void SaveMap( TMap &MP, QDataStream &ST )
    {
      // 1
      ST << MP.size();
      // 2
      for ( typename TMap::iterator I = MP.begin(); I != MP.end(); ++I ) {
        ST << (*I).first;
        ST << (*I).second;
      }
    }

    template< class TVector, class TValue >
    static void LoadVector( TVector &VC, QDataStream &ST )
    {
      // 1
      std::size_t L;
      ST >> L;
      // 2
      TValue AValue;
      for ( std::size_t I = 0; I < L; ++I ) {
        ST >> AValue;
        VC.push_back( AValue );
      }
    }

    template< class TVector >
    static void SaveVector( TVector &VC, QDataStream &ST )
    {
      // 1
      ST << VC.size();
      // 2
      for ( typename TVector::iterator I = VC.begin(); I != VC.end(); ++I ) {
        ST << (*I);
      }
    }

    bool LoadObject( void* O,    QStorageKind AStorageKind, QStorager* ST, const QString& AKeyStorage = "" );
    void SaveObject( void* O,    QStorageKind AStorageKind, QStorager* ST, const QString& AKeyStorage = "" );
    void RemoveMemory( void* O, const QString& AKeyStorage = "" );
    void ClearMemory() { m_MapMemoryStorage.clear(); };

    void SaveToStreamPrepareHistory( QComboBox *CB, QDataStream &ST, int HistoryCount );
    void LoadFromStream( QDataStream &ST );
    void SaveToStream( QDataStream &ST );
};

class QStorageDB : public QStorage
{
  private:
    using inherited = QStorage;
  public:
    QStorageDB();
    virtual ~QStorageDB();
    QStorageDB( QStorageDB&& A );
    QStorageDB( const QStorageDB& A );
    QStorageDB& operator = ( const QStorageDB& A );
    QStorageDB& operator = ( QStorageDB&& A );

    QSqlDatabase* m_Database = nullptr;
    QString m_Schema;
    void SetDatabase( QSqlDatabase* Value );
    virtual QString PrefixKeyStorage() override;
    virtual void ResetSettings() override;
  protected:
    QSqlQuery* m_Query = nullptr;
    QString m_SQL;
    virtual bool BeginLoadDB() override;
    virtual void EndLoadDB() override;
    virtual void BeginSaveDB() override;
    virtual void EndSaveDB() override;
};

class QStoragerMainWindow : public QStorager
{
  public:
    QStoragerMainWindow();
    virtual ~QStoragerMainWindow();
  private:
    using inherited = QStorager;
  public:
    virtual void LoadFromStream( void *AObject, QDataStream &ST );
    virtual void SaveToStream(   void *AObject, QDataStream &ST );
};

class QStoragerDialog : public QStorager
{
  public:
    QStoragerDialog();
    virtual ~QStoragerDialog();
  private:
    using inherited = QStorager;
  public:
    virtual void LoadFromStream( void *AObject, QDataStream &ST );
    virtual void SaveToStream(   void *AObject, QDataStream &ST );
};

extern const QChar CharPercent;
extern const QChar CharUnderline;

bool Like( QString::iterator t_end, QString::iterator s_end, QString::iterator t, QString::iterator s );

enum class QGender : int
{
    Male
  , Avg
  , Female
};

enum class QNumberWordDiapazon : int
{
    One
  , TwoFourth
  , Five
};

void RetranslateStrings();
QString StringOfChar( QChar C, int Count );
QNumberWordDiapazon NumberWordDiapazon( char16_t C, bool B );
QString ThreeNumberToWords( const QString &S
                          , int P
                          , QGender AGender
                          , QNumberWordDiapazon &ADiapazon );
QString StringNumberToWords( QString AStringNumber
                           , QGender AGender
                           , QString (&ACounted)[3]
                           , bool FirstUpper );
void PrabhupadaMessage( const QString &msg
                      , const QString &title = ""
                      , QWidget *parent = nullptr );
void SetRetranslateIcon( QIcon& AIcon
                       , const QString& ADir
                       , const QString& AFileName
                       , QAction* AAction
                       , bool AIconVisibleInMenu
                       , const QString& ALanguage );

class QClassicLog : public QObject
{
  CS_OBJECT( QClassicLog )

  public:
    QClassicLog( QObject *parent = nullptr );
    QClassicLog( QClassicLog&& A ) = delete;
    QClassicLog( const QClassicLog& A ) = delete;
    QClassicLog& operator = ( const QClassicLog& A ) = delete;
    QClassicLog& operator = ( QClassicLog&& A ) = delete;
    ~QClassicLog();
    static QSaveFile *m_SaveFile;
    static QTextStream *m_Stream;
    static bool StartLog( const QString &AFileLog );
    static void FinishLog();
    static void Log( const QString &ALogString );
  private:
    using inherited = QObject;
};

#ifdef QT_DEBUG
  #define StartPrabhupadaLog( S )  QClassicLog::StartLog( S )
  #define FinishPrabhupadaLog()    QClassicLog::FinishLog()
  #define PrabhupadaLog( S )       QClassicLog::Log( S )
#else
  #define StartPrabhupadaLog( S )
  #define FinishPrabhupadaLog()
  #define PrabhupadaLog( S )
#endif

#endif
