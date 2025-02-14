#include <QPrabhupadaDictionary.h>
#include <memory>
#include <algorithm>

QPrabhupadaPrimer QPrabhupadaDictionary::PrabhupadaPrimer;
const QString QPrabhupadaDictionary::PrabhupadaDictionaryFiles  = QString( "./resources/PrabhupadaDictionaryFiles/" );
const QString QPrabhupadaDictionary::PrabhupadaDictionaryLang   = QString( "./resources/Lang/" );
const QString QPrabhupadaDictionary::PrabhupadaDictionaryImages = QString( "./resources/Images/" );

QFilterSlovar::QFilterSlovar()
{
}

QFilterSlovar::QFilterSlovar( const QFilterSlovar& A )
  : m_PrabhupadaFindOptions    ( A.m_PrabhupadaFindOptions )
  , m_Sanskrit                 ( A.m_Sanskrit )
  , m_Translate                ( A.m_Translate )
  , m_SanskritWithoutDiakritik ( A.m_SanskritWithoutDiakritik )
  , m_TranslateWithoutDiakritik( A.m_TranslateWithoutDiakritik )
{
}

QFilterSlovar::QFilterSlovar( QFilterSlovar&& A )
  : m_PrabhupadaFindOptions    ( std::move( A.m_PrabhupadaFindOptions ) )
  , m_Sanskrit                 ( std::move( A.m_Sanskrit ) )
  , m_Translate                ( std::move( A.m_Translate ) )
  , m_SanskritWithoutDiakritik ( std::move( A.m_SanskritWithoutDiakritik ) )
  , m_TranslateWithoutDiakritik( std::move( A.m_TranslateWithoutDiakritik ) )
{
}

QFilterSlovar::QFilterSlovar( QPrabhupadaFindOptions APrabhupadaFindOptions
                            , const QString &ASanskrit
                            , const QString &ATranslate )
  : m_PrabhupadaFindOptions( APrabhupadaFindOptions )
  , m_Sanskrit             ( ASanskrit )
  , m_Translate            ( ATranslate )
{
  m_SanskritWithoutDiakritik  = QPrabhupadaDictionary::RemoveDiacritics( m_Sanskrit );
  m_TranslateWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( m_Translate );
}

QFilterSlovar::~QFilterSlovar()
{
}

QFilterSlovar& QFilterSlovar::operator = ( const QFilterSlovar& A )
{
  m_PrabhupadaFindOptions     = A.m_PrabhupadaFindOptions;
  m_Sanskrit                  = A.m_Sanskrit;
  m_Translate                 = A.m_Translate;
  m_SanskritWithoutDiakritik  = A.m_SanskritWithoutDiakritik;
  m_TranslateWithoutDiakritik = A.m_TranslateWithoutDiakritik;

  return *this;
}

QFilterSlovar& QFilterSlovar::operator = ( QFilterSlovar&& A )
{
  m_PrabhupadaFindOptions     = std::move( A.m_PrabhupadaFindOptions );
  m_Sanskrit                  = std::move( A.m_Sanskrit );
  m_Translate                 = std::move( A.m_Translate );
  m_SanskritWithoutDiakritik  = std::move( A.m_SanskritWithoutDiakritik );
  m_TranslateWithoutDiakritik = std::move( A.m_TranslateWithoutDiakritik );

  return *this;
}

void QFilterSlovar::SetSanskrit( const QString &Value )
{
  if ( m_Sanskrit != Value ) {
    m_Sanskrit = Value;
    m_SanskritWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( m_Sanskrit );
  }
}

void QFilterSlovar::SetTranslate( const QString &Value )
{
  if ( m_Translate != Value ) {
    m_Translate = Value;
    m_TranslateWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( m_Translate );
  }
}

void QFilterSlovar::LoadFromStream( QDataStream &ST )
{
  QString S;

  // 1
  ST >> m_PrabhupadaFindOptions;
  // 2
  ST >> S;
  SetSanskrit( S );
  // 3
  ST >> S;
  SetTranslate( S );
  // нет нужды запоминать служебные поля, так как они заполняются автоматически через методы SetSanskrit() и SetTranslate()!
  // SanskritWithoutDiakritik
  // TranslateWithoutDiakritik
}

void QFilterSlovar::SaveToStream( QDataStream &ST )
{
  // 1, 2, 3
  ST << m_PrabhupadaFindOptions << m_Sanskrit << m_Translate;
}

QPrabhupadaLetter::QPrabhupadaLetter()
{
}

QPrabhupadaLetter::~QPrabhupadaLetter()
{
}

QPrabhupadaPrimer::QPrabhupadaPrimer()
  : inherited()
{
}

QPrabhupadaPrimer::~QPrabhupadaPrimer()
{
}

QPrabhupadaSlovarVector::QPrabhupadaSlovarVector()
  : inherited()
{
}

QPrabhupadaSlovarVector::~QPrabhupadaSlovarVector()
{
  Clear();
}

void QPrabhupadaSlovarVector::Clear()
{
  for ( iterator I = begin(); I != end(); ++I ) {
    delete *I;
  }
  clear();
  m_SearchCount = 0;
}

QSanskritTranslate::QSanskritTranslate()
{
}

QSanskritTranslate::~QSanskritTranslate()
{
}

QPrabhupadaFindOptions::QPrabhupadaFindOptions()
{
}

QPrabhupadaFindOptions::QPrabhupadaFindOptions( bool ACaseSensitive
                                              , bool ARegularExpression
                                              , bool AAutoPercentBegin
                                              , bool AAutoPercentEnd )
  : m_CaseSensitive    ( ACaseSensitive )
  , m_RegularExpression( ARegularExpression )
  , m_AutoPercentBegin ( AAutoPercentBegin )
  , m_AutoPercentEnd   ( AAutoPercentEnd )
{
}

QPrabhupadaFindOptions::QPrabhupadaFindOptions( const QPrabhupadaFindOptions& A )
  : m_CaseSensitive    ( A.m_CaseSensitive )
  , m_RegularExpression( A.m_RegularExpression )
  , m_AutoPercentBegin ( A.m_AutoPercentBegin )
  , m_AutoPercentEnd   ( A.m_AutoPercentEnd )
{
}

QPrabhupadaFindOptions::QPrabhupadaFindOptions( QPrabhupadaFindOptions&& A )
  : m_CaseSensitive    ( std::move( A.m_CaseSensitive ) )
  , m_RegularExpression( std::move( A.m_RegularExpression ) )
  , m_AutoPercentBegin ( std::move( A.m_AutoPercentBegin ) )
  , m_AutoPercentEnd   ( std::move( A.m_AutoPercentEnd ) )
{
}

QPrabhupadaFindOptions::~QPrabhupadaFindOptions()
{
}


QPrabhupadaFindOptions& QPrabhupadaFindOptions::operator = ( const QPrabhupadaFindOptions& A )
{
  m_CaseSensitive     = A.m_CaseSensitive;
  m_RegularExpression = A.m_RegularExpression;
  m_AutoPercentBegin  = A.m_AutoPercentBegin;
  m_AutoPercentEnd    = A.m_AutoPercentEnd;

  return *this;
}

QPrabhupadaFindOptions& QPrabhupadaFindOptions::operator = ( QPrabhupadaFindOptions&& A )
{
  m_CaseSensitive     = std::move( A.m_CaseSensitive );
  m_RegularExpression = std::move( A.m_RegularExpression );
  m_AutoPercentBegin  = std::move( A.m_AutoPercentBegin );
  m_AutoPercentEnd    = std::move( A.m_AutoPercentEnd );

  return *this;
}

void QPrabhupadaFindOptions::LoadFromStream( QDataStream &ST )
{
  // 1, 2, 3, 4
  ST >> m_CaseSensitive >> m_RegularExpression >> m_AutoPercentBegin >> m_AutoPercentEnd;
}

void QPrabhupadaFindOptions::SaveToStream( QDataStream &ST )
{
  // 1, 2, 3, 4
  ST << m_CaseSensitive << m_RegularExpression << m_AutoPercentBegin << m_AutoPercentEnd;
}

QPrabhupadaZakladka::QPrabhupadaZakladka()
{
}

QPrabhupadaZakladka::QPrabhupadaZakladka( int ARowNum
                                        , int AColumnNum
                                        , QFilterSlovar AFilterSlovar )
  : m_RowNum( ARowNum )
  , m_ColumnNum( AColumnNum )
  , m_FilterSlovar( AFilterSlovar )
{
}

QPrabhupadaZakladka::QPrabhupadaZakladka( const QPrabhupadaZakladka& A )
  : m_RowNum      ( A.m_RowNum )
  , m_ColumnNum   ( A.m_ColumnNum )
  , m_FilterSlovar( A.m_FilterSlovar )
{
}

QPrabhupadaZakladka::QPrabhupadaZakladka( QPrabhupadaZakladka&& A )
  : m_RowNum      ( std::move( A.m_RowNum ) )
  , m_ColumnNum   ( std::move( A.m_ColumnNum ) )
  , m_FilterSlovar( std::move( A.m_FilterSlovar ) )
{
}

QPrabhupadaZakladka::~QPrabhupadaZakladka()
{
}

QPrabhupadaZakladka& QPrabhupadaZakladka::operator = ( const QPrabhupadaZakladka& A )
{
  m_RowNum       = A.m_RowNum;
  m_ColumnNum    = A.m_ColumnNum;
  m_FilterSlovar = A.m_FilterSlovar;

  return *this;
}

QPrabhupadaZakladka& QPrabhupadaZakladka::operator = ( QPrabhupadaZakladka&& A )
{
  m_RowNum       = std::move( A.m_RowNum );
  m_ColumnNum    = std::move( A.m_ColumnNum );
  m_FilterSlovar = std::move( A.m_FilterSlovar );

  return *this;
}

void QPrabhupadaZakladka::LoadFromStream( QDataStream &ST )
{
  // 1
  ST >> m_RowNum;
  // 2
  ST >> m_ColumnNum;
  // 3
  m_FilterSlovar.LoadFromStream( ST );
}

void QPrabhupadaZakladka::SaveToStream( QDataStream &ST )
{
  // 1
  ST << m_RowNum;
  // 2
  ST << m_ColumnNum;
  // 3
  m_FilterSlovar.SaveToStream( ST );
}

QPrabhupadaZakladkaMap::QPrabhupadaZakladkaMap()
  : inherited()
{
}

QPrabhupadaZakladkaMap::QPrabhupadaZakladkaMap( const QPrabhupadaZakladkaMap& A )
  : inherited( A )
{
}

QPrabhupadaZakladkaMap::QPrabhupadaZakladkaMap( QPrabhupadaZakladkaMap&& A )
  : inherited( std::move( A ) )
{
}

QPrabhupadaZakladkaMap::~QPrabhupadaZakladkaMap()
{
}

QPrabhupadaZakladkaMap& QPrabhupadaZakladkaMap::operator = ( const QPrabhupadaZakladkaMap& A )
{
  inherited::operator = ( A );

  return *this;
}

QPrabhupadaZakladkaMap& QPrabhupadaZakladkaMap::operator = ( QPrabhupadaZakladkaMap&& A )
{
  inherited::operator = ( std::move( A ) );

  return *this;
}

void QPrabhupadaZakladkaMap::LoadFromStream( QDataStream &ST )
{
  // 1
  QPrabhupadaZakladka PZ;
  unsigned short I;
  std::size_t L;
  ST >> L;
  clear();
  for ( std::size_t i = 0; i < L; ++i ) {
    ST >> I;
    PZ.LoadFromStream( ST );
    operator[]( I ) = PZ;
  }
}

void QPrabhupadaZakladkaMap::SaveToStream( QDataStream &ST )
{
  // 1
  ST << size();
  for ( iterator I = begin(); I != end(); ++I ) {
    ST << (*I).first;
    (*I).second.SaveToStream( ST );
  }
}

QLanguageInfoPrabhupadaDictionary::QLanguageInfoPrabhupadaDictionary()
  : inherited()
{
}

QLanguageInfoPrabhupadaDictionary::QLanguageInfoPrabhupadaDictionary( const QLanguageInfoPrabhupadaDictionary &A )
  : inherited( A )
  , m_PrabhupadaZakladka   ( A.m_PrabhupadaZakladka )
  , m_PrabhupadaZakladkaMap( A.m_PrabhupadaZakladkaMap )
{
}

QLanguageInfoPrabhupadaDictionary::QLanguageInfoPrabhupadaDictionary( QLanguageInfoPrabhupadaDictionary&& A )
  : inherited( std::move( A ) )
  , m_PrabhupadaZakladka   ( std::move( A.m_PrabhupadaZakladka ) )
  , m_PrabhupadaZakladkaMap( std::move( A.m_PrabhupadaZakladkaMap ) )
{
}

QLanguageInfoPrabhupadaDictionary& QLanguageInfoPrabhupadaDictionary::operator = ( const QLanguageInfoPrabhupadaDictionary& A )
{
  inherited::operator = ( A );
  m_PrabhupadaZakladka    = A.m_PrabhupadaZakladka;
  m_PrabhupadaZakladkaMap = A.m_PrabhupadaZakladkaMap;

  return *this;
}

QLanguageInfoPrabhupadaDictionary& QLanguageInfoPrabhupadaDictionary::operator = ( QLanguageInfoPrabhupadaDictionary&& A )
{
  inherited::operator = ( std::move( A ) );
  m_PrabhupadaZakladka    = std::move( A.m_PrabhupadaZakladka );
  m_PrabhupadaZakladkaMap = std::move( A.m_PrabhupadaZakladkaMap );

  return *this;
}

QLanguageInfoPrabhupadaDictionary::~QLanguageInfoPrabhupadaDictionary()
{
}

void QLanguageInfoPrabhupadaDictionary::LoadFromStream( QDataStream& ST )
{
  inherited::LoadFromStream( ST );

  m_PrabhupadaZakladka.LoadFromStream( ST );
  m_PrabhupadaZakladkaMap.LoadFromStream( ST );
}

void QLanguageInfoPrabhupadaDictionary::SaveToStream( QDataStream& ST )
{
  inherited::SaveToStream( ST );

  m_PrabhupadaZakladka.SaveToStream( ST );
  m_PrabhupadaZakladkaMap.SaveToStream( ST );
}

QLanguageVectorPrabhupadaDictionary::QLanguageVectorPrabhupadaDictionary()
  : inherited()
{
}

QLanguageVectorPrabhupadaDictionary::QLanguageVectorPrabhupadaDictionary( const QLanguageVectorPrabhupadaDictionary& A )
  : inherited( A )
{
}

QLanguageVectorPrabhupadaDictionary::QLanguageVectorPrabhupadaDictionary( QLanguageVectorPrabhupadaDictionary&& A )
  : inherited( std::move( A ) )
{
}

QLanguageVectorPrabhupadaDictionary::~QLanguageVectorPrabhupadaDictionary()
{
}

QPrabhupadaDictionary::QPrabhupadaDictionary( QObject *parent )
  : inherited( parent )
{
  m_LanguageUIIndex.setObjectName( "m_LanguageUIIndex" );

  PreparePrabhupadaPrimer();
  QObject::connect( &m_LanguageIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                   , &QPrabhupadaDictionary::LanguageIndexChanged );
  QObject::connect( &m_LanguageUIIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionary::LanguageUIIndexChanged );
  QObject::connect( &m_PrabhupadaOrder
                  , &QPrabhupadaOrder::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionary::OrderByChanged );
  QObject::connect( &m_CaseSensitive
                  , &QEmitBool::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionary::CaseSensitiveChanged );
  QObject::connect( &m_RegularExpression
                  , &QEmitBool::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionary::RegularExpressionChanged );
  QObject::connect( &m_AutoPercentBegin
                  , &QEmitBool::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionary::AutoPercentBeginChanged );
  QObject::connect( &m_AutoPercentEnd
                  , &QEmitBool::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionary::AutoPercentEndChanged );
  QObject::connect( &m_PrabhupadaFilterSlovar
                  , &QPrabhupadaFilterSlovar::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionary::FilterSlovarChanged );
  QObject::connect( &m_PrabhupadaZakladka
                  , &QEmitPrabhupadaZakladka::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionary::PrabhupadaZakladkaChanged );
}

QPrabhupadaDictionary::~QPrabhupadaDictionary()
{
}

QString QPrabhupadaDictionary::RemoveDiacritics( const QString& S )
{
  QString R;

  int L = S.length();
  QPrabhupadaPrimer::iterator F;
  for ( int i = 0; i < L; ++i ) {
    F = PrabhupadaPrimer.find( S[ i ] );
    if ( F != PrabhupadaPrimer.end() ) {
      R += (*F).second.m_Letter;
    } else {
      R += S[ i ];
    }
  }
  return R;
}

bool QPrabhupadaDictionary::PrabhupadaCompareLess( const QString& A, const QString& B )
{
  QString8::size_type AL = A.length()
                    , BL = B.length();

  QString8::size_type L = std::min( AL, BL );

  int AV, BV;
  for ( QString8::size_type i = 0; i < L; ++i ) {
    AV = PrabhupadaPrimer[ A[ i ] ].m_Ves;
    BV = PrabhupadaPrimer[ B[ i ] ].m_Ves;
    if ( AV == BV ) {
      continue;
    } else if ( AV > BV ) {
      return false;
    } else if ( AV < BV ) {
      return true;
    }
  }

  if ( AL < BL )
    return true;

  return false;
}

bool QPrabhupadaDictionary::PrabhupadaCompareMore( const QString& A, const QString& B )
{
  QString8::size_type AL = A.length()
                    , BL = B.length();

  QString8::size_type L = std::min( AL, BL );

  int AV, BV;
  for ( QString8::size_type i = 0; i < L; ++i ) {
    AV = PrabhupadaPrimer[ A[ i ] ].m_Ves;
    BV = PrabhupadaPrimer[ B[ i ] ].m_Ves;
    if ( AV == BV ) {
      continue;
    } else if ( AV < BV ) {
      return false;
    } else if ( AV > BV ) {
      return true;
    }
  }

  if ( AL > BL )
    return true;

  return false;
}

void QPrabhupadaDictionary::PreparePrabhupadaPrimer()
{
  QPrabhupadaLetter B;

  QFile AFile( PrabhupadaDictionaryFiles + "PrabhupadaPrimer.txt" );
  QTextStream AStream( &AFile );
  AFile.open( QIODevice::ReadOnly );

  int V = 0;
  QString S;
  while ( true ) {
    S = AStream.readLine();
    if ( S.length() < 3 ) {
      break;
    }

    B.m_Letter = S[ 2 ];
    B.m_Ves = ++V;

    PrabhupadaPrimer[ S[ 0 ] ] = B;
  }
}

void QPrabhupadaDictionary::PrepareLanguageAndMaxID()
{
  if ( m_DB != nullptr && m_DB->isOpen () ) {
    QSqlQuery qu( *m_DB );

    if ( !m_LanguageVector.m_LoadSuccess ) {
      qu.exec( QString( "select\n"
                        "  a.\"ID\"\n"
                        ", a.\"LANGUAGE\"\n"
                        ", a.\"LANGUAGE_WORD\"\n"
                        "from\n"
                        "    %1\"LANGUAGES\" a\n"
                        "order by a.\"LANGUAGE_WORD\";" ).formatArgs( m_Schema ) );

      QLanguageInfo* YI;

      while ( qu.next() ) {
        YI = m_LanguageVector.NewLanguageInfo();

        YI->m_ID            = qu.value( 0 ).toInt();
        YI->m_Language      = qu.value( 1 ).toString();
        YI->m_LanguageSlovo = qu.value( 2 ).toString();

        m_LanguageVector.push_back( YI );
      }
    }

    qu.clear();
    qu.exec( QString( "select max( a.\"ID\" ) as \"MAX_ID\" from %1\"SANSKRIT\" a;" ).formatArgs( m_Schema ) );
    qu.next();

    m_MaxID = qu.value( 0 ).toInt();
  }
}

void QPrabhupadaDictionary::PreparePrabhupadaSlovarVector()
{
  if ( m_DB != nullptr && m_DB->isOpen () ) {
    QSqlQuery qu( *m_DB );

    qu.prepare( QString( "select\n"
                         "  a.\"ID\"\n"
                         ", a.\"ORIGINAL\"\n"
                         ", a.\"TRANSLATE\"\n"
                         "from\n"
                         "    %1\"SANSKRIT\" a\n"
                         "where\n"
                         "    a.\"LANGUAGE\" = :LANGUAGE;" ).formatArgs( m_Schema ) );
    qu.bindValue( ":LANGUAGE", m_LanguageVector[ (std::size_t)m_LanguageIndex.m_Value ]->m_Language );
    qu.exec();
    QSanskritTranslate *ST;

    m_PrabhupadaSlovarVector.Clear();

    while ( qu.next() ) {
      ST = new QSanskritTranslate();

      ST->m_ID                        = qu.value( 0 ).toInt();
      ST->m_Sanskrit                  = qu.value( 1 ).toString();
      ST->m_Translate                 = qu.value( 2 ).toString();
      ST->m_SanskritWithoutDiakritik  = QPrabhupadaDictionary::RemoveDiacritics( ST->m_Sanskrit );
      ST->m_TranslateWithoutDiakritik = QPrabhupadaDictionary::RemoveDiacritics( ST->m_Translate  );
      m_PrabhupadaSlovarVector.push_back( ST );
    }
    m_PrabhupadaOrder.EmitValueChanged( true );
    endResetModel();
    m_LanguageIndex.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::LoadFromStream( QDataStream &ST )
{
  // m_LanguageUIIndex загружается в main() из файла!
  // 1
  m_LanguageIndex.LoadFromStream( ST );
  // 2
  m_FontSize.LoadFromStream( ST );
  // 3
  m_PrabhupadaOrder.LoadFromStream( ST );
}

void QPrabhupadaDictionary::SaveToStream( QDataStream &ST )
{
  // m_LanguageUIIndex сохраняется в QPrabhupadaDictionaryWindow::closeEvent() в файл!
  // 1
  m_LanguageIndex.SaveToStream( ST );
  // 2
  m_FontSize.SaveToStream( ST );
  // 3
  m_PrabhupadaOrder.SaveToStream( ST );
}

void QPrabhupadaDictionary::LanguageIndexChanged( int Value )
{
  if ( m_LanguageIndex.m_NeedMainWork ) {
    std::size_t L = m_LanguageVector.size();
    if ( Value >= 0 && L > Value ) {
      PreparePrabhupadaSlovarVector();

      QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_LanguageVector[ Value ] );
      m_PrabhupadaZakladka.SetValue( YI->m_PrabhupadaZakladka );

      m_LanguageIndex.m_NeedMainWork = false;
    }
  }
}

void QPrabhupadaDictionary::LanguageUIIndexChanged( int Value )
{
  if ( m_LanguageUIIndex.m_NeedMainWork ) {
    std::size_t L = m_LanguageVector.size();
    if ( Value >= 0 && L > Value ) {
      QString AFileTranslate = "PrabhupadaDictionary_" + m_LanguageVector[ Value ]->m_Language + ".qm";
      if ( m_Translator.load( AFileTranslate, PrabhupadaDictionaryLang ) ) {
        qApp->installTranslator( &m_Translator );
        QGuiApplication::setApplicationDisplayName( tr( "Словарь Шрилы Прабхупады!" ) );
        RetranslateStrings();
        m_LanguageUIIndex.m_NeedMainWork = false;
      } else {
        QString S = tr( "Не удалось загрузить файл перевода " ) + AFileTranslate;
        PrabhupadaMessage( S );
      }
    }
  }
}

void QPrabhupadaDictionary::FilterSlovarChanged( QFilterSlovar Value )
{
  if ( m_PrabhupadaFilterSlovar.m_NeedMainWork ) {

    m_FilterSlovarIsEmpty = Value.GetIsEmpty();
    m_PrabhupadaSlovarVector.m_SearchCount = 0;

    if ( !m_FilterSlovarIsEmpty ) {
      int ActualIndex = -1;
      bool CheckSanskrit  = !Value.m_SanskritWithoutDiakritik.isEmpty(),
           CheckTranslate = !Value.m_TranslateWithoutDiakritik.isEmpty();

      bool NeedSanskrit
         , NeedTranslate;

      std::size_t L = m_PrabhupadaSlovarVector.size();
      // qint64 T_Start = QDateTime::currentMSecsSinceEpoch();

      if ( Value.m_PrabhupadaFindOptions.m_RegularExpression ) {
        QPatternOptionFlags RO = QPatternOption::MultilineOption;
        if ( !Value.m_PrabhupadaFindOptions.m_CaseSensitive ) {
          RO = RO | QPatternOption::CaseInsensitiveOption;
        }
        QRegularExpression reSanskrit ( Value.m_SanskritWithoutDiakritik,  RO )
                         , reTranslate( Value.m_TranslateWithoutDiakritik, RO );
        for ( int I = 0; I < L; ++I ) {
          NeedTranslate = false;

          NeedSanskrit = CheckSanskrit ? reSanskrit.match( m_PrabhupadaSlovarVector[ I ]->m_SanskritWithoutDiakritik ).hasMatch() : true;
          if ( NeedSanskrit ) {
            NeedTranslate  = CheckTranslate ? reTranslate.match( m_PrabhupadaSlovarVector[ I ]->m_TranslateWithoutDiakritik ).hasMatch() : true;
          }
          if ( NeedTranslate ) {
            m_PrabhupadaSlovarVector[ ++ActualIndex ]->m_SearchIndex = I;
          }
        }
      } else {
        QString ASanskritWithoutDiakritik  = Value.m_SanskritWithoutDiakritik
              , ATranslateWithoutDiakritik = Value.m_TranslateWithoutDiakritik;

        if ( Value.m_PrabhupadaFindOptions.m_AutoPercentBegin ) {
          ASanskritWithoutDiakritik  = CharPercent + ASanskritWithoutDiakritik;
          ATranslateWithoutDiakritik = CharPercent + ATranslateWithoutDiakritik;
        }

        if ( Value.m_PrabhupadaFindOptions.m_AutoPercentEnd ) {
          ASanskritWithoutDiakritik  = ASanskritWithoutDiakritik  + CharPercent;
          ATranslateWithoutDiakritik = ATranslateWithoutDiakritik + CharPercent;
        }

        for ( int I = 0; I < L; ++I ) {
          NeedTranslate = false;

          if ( CheckSanskrit ) {
            NeedSanskrit = Like( ASanskritWithoutDiakritik.end()
                               , m_PrabhupadaSlovarVector[ I ]->m_SanskritWithoutDiakritik.end()
                               , ASanskritWithoutDiakritik.begin()
                               , m_PrabhupadaSlovarVector[ I ]->m_SanskritWithoutDiakritik.begin() );
          } else {
            NeedSanskrit = true;
          }
          if ( NeedSanskrit ) {
            if ( CheckTranslate ) {
                NeedTranslate = Like( ATranslateWithoutDiakritik.end()
                                    , m_PrabhupadaSlovarVector[ I ]->m_TranslateWithoutDiakritik.end()
                                    , ATranslateWithoutDiakritik.begin()
                                    , m_PrabhupadaSlovarVector[ I ]->m_TranslateWithoutDiakritik.begin() );
            } else {
              NeedTranslate = true;
            }
          }
          if ( NeedTranslate ) {
            m_PrabhupadaSlovarVector[ ++ActualIndex ]->m_SearchIndex = I;
          }
        }
      }

      // qint64 T_Finish = QDateTime::currentMSecsSinceEpoch();
      // PrabhupadaMessage( "Cicle time == " + QString::number( T_Finish - T_Start ) );

      m_PrabhupadaSlovarVector.m_SearchCount = ActualIndex + 1;
    } else {
      m_PrabhupadaSlovarVector.m_SearchCount = (int)m_PrabhupadaSlovarVector.size();
    }
    m_PrabhupadaFilterSlovar.m_NeedMainWork = false;
    endResetModel();
  }
}

void QPrabhupadaDictionary::PrabhupadaZakladkaChanged( QPrabhupadaZakladka Value )
{
  if ( m_PrabhupadaZakladka.m_NeedMainWork ) {
    // Устанавливаем фильтр!
    m_PrabhupadaFilterSlovar.SetValue( Value.m_FilterSlovar );

    m_PrabhupadaZakladka.m_NeedMainWork = false;
  }
}

int QPrabhupadaDictionary::rowCount( const QModelIndex& /*parent*/ ) const
{
  int N = m_FilterSlovarIsEmpty ? (int)m_PrabhupadaSlovarVector.size() : m_PrabhupadaSlovarVector.m_SearchCount;
  return N;
}

int QPrabhupadaDictionary::columnCount( const QModelIndex& /*parent*/ ) const
{
  return 2;
}

QVariant QPrabhupadaDictionary::data( const QModelIndex &index, int role ) const
{
  int row = index.row();
  int col = index.column();

  switch ( role ) {
  case Qt::DisplayRole:
    if ( m_FilterSlovarIsEmpty ) {
      if ( col == 0 ) {
        return m_PrabhupadaSlovarVector[ row ]->m_Sanskrit;
      } else {
        return m_PrabhupadaSlovarVector[ row ]->m_Translate;
      }
    } else {
      if ( col == 0 )
        return m_PrabhupadaSlovarVector[ m_PrabhupadaSlovarVector[ row ]->m_SearchIndex ]->m_Sanskrit;
      else
        return m_PrabhupadaSlovarVector[ m_PrabhupadaSlovarVector[ row ]->m_SearchIndex ]->m_Translate;
    }
  // case Qt::FontRole:
  //   if ( row % 2 == 1 ) {
  //     QFont boldFont;
  //     boldFont.setBold(true);
  //     return boldFont;
  //   }
  //   break;
  // case Qt::BackgroundRole:
  //   if ( row % 2 == 0 )
  //     return QBrush( Qt::yellow );
  //   break;
  // case Qt::TextAlignmentRole:
  //   if ( row == 1 && col == 1 )
  //     return int( Qt::AlignRight | Qt::AlignVCenter );
  //   break;
  // case Qt::CheckStateRole:
  //   if ( row == 1 && col == 0 )
  //     return Qt::Checked;
  //   break;
  }
  return QVariant();
}

QVariant QPrabhupadaDictionary::headerData( int section, Qt::Orientation orientation, int role ) const
{
  if ( role == Qt::DisplayRole && orientation == Qt::Horizontal ) {
    switch ( section ) {
      case 0:
        return QString( tr( "Санскрит" ) );
      case 1:
        return QString( tr( "Перевод" ) );
    }
  }
  return QVariant();
}

void QPrabhupadaDictionary::sortByColumn( int column, Qt::SortOrder order )
{
  if ( column == 0 ) {
    if ( order == Qt::AscendingOrder ) {
      m_PrabhupadaOrder.SetValue( QPrabhupadaDictionaryOrderBy::SanskritIncreasing );
    } else {
      m_PrabhupadaOrder.SetValue( QPrabhupadaDictionaryOrderBy::SanskritDecreasing );
    }
  } else {
    if ( order == Qt::AscendingOrder ) {
      m_PrabhupadaOrder.SetValue( QPrabhupadaDictionaryOrderBy::TranslateIncreasing );
    } else {
      m_PrabhupadaOrder.SetValue( QPrabhupadaDictionaryOrderBy::TranslateDecreasing );
    }
  }
}

void QPrabhupadaDictionary::OrderByChanged( QPrabhupadaDictionaryOrderBy Value )
{
  if ( m_PrabhupadaOrder.m_NeedMainWork ) {
    switch ( Value ) {
      case QPrabhupadaDictionaryOrderBy::SanskritIncreasing :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Sanskrit == B->m_Sanskrit ?
                              PrabhupadaCompareLess( A->m_Translate, B->m_Translate  ) :
                              PrabhupadaCompareLess( A->m_Sanskrit,  B->m_Sanskrit );
                   }
                 );
        break;
      case QPrabhupadaDictionaryOrderBy::SanskritDecreasing :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Sanskrit == B->m_Sanskrit ?
                              PrabhupadaCompareMore( A->m_Translate, B->m_Translate  ) :
                              PrabhupadaCompareMore( A->m_Sanskrit,  B->m_Sanskrit );
                   }
                 );
        break;
      case QPrabhupadaDictionaryOrderBy::TranslateIncreasing :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Translate == B->m_Translate ?
                              PrabhupadaCompareLess( A->m_Sanskrit,  B->m_Sanskrit ) :
                              PrabhupadaCompareLess( A->m_Translate, B->m_Translate  );
                   }
                 );
        break;
      case QPrabhupadaDictionaryOrderBy::TranslateDecreasing :
        std::sort( m_PrabhupadaSlovarVector.begin()
                 , m_PrabhupadaSlovarVector.end()
                 , [] ( const QSanskritTranslate *A, const QSanskritTranslate *B )
                   {
                     return A->m_Translate == B->m_Translate ?
                              PrabhupadaCompareMore( A->m_Sanskrit,  B->m_Sanskrit ) :
                              PrabhupadaCompareMore( A->m_Translate, B->m_Translate  );
                   }
                 );
        break;
    }
    m_PrabhupadaFilterSlovar.EmitValueChanged( true );
    // emit modelReset() вызывается при фильтрации!;
    m_PrabhupadaOrder.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::CaseSensitiveChanged( bool Value )
{
  if ( m_CaseSensitive.m_NeedMainWork ) {
    QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_LanguageVector[ (std::size_t)m_LanguageIndex.m_Value ] );
    YI->m_PrabhupadaZakladka.m_FilterSlovar.m_PrabhupadaFindOptions.m_CaseSensitive = Value;
    m_CaseSensitive.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::RegularExpressionChanged( bool Value )
{
  if ( m_RegularExpression.m_NeedMainWork ) {
    QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_LanguageVector[ (std::size_t)m_LanguageIndex.m_Value ] );
    YI->m_PrabhupadaZakladka.m_FilterSlovar.m_PrabhupadaFindOptions.m_RegularExpression = Value;
    m_RegularExpression.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::AutoPercentBeginChanged( bool Value )
{
  if ( m_AutoPercentBegin.m_NeedMainWork ) {
    QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_LanguageVector[ (std::size_t)m_LanguageIndex.m_Value ] );
    YI->m_PrabhupadaZakladka.m_FilterSlovar.m_PrabhupadaFindOptions.m_AutoPercentBegin = Value;
    m_AutoPercentBegin.m_NeedMainWork = false;
  }
}

void QPrabhupadaDictionary::AutoPercentEndChanged( bool Value )
{
  if ( m_AutoPercentEnd.m_NeedMainWork ) {
    QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_LanguageVector[ (std::size_t)m_LanguageIndex.m_Value ] );
    YI->m_PrabhupadaZakladka.m_FilterSlovar.m_PrabhupadaFindOptions.m_AutoPercentEnd = Value;
    m_AutoPercentEnd.m_NeedMainWork = false;
  }
}

QStoragerPrabhupadaDictionary::QStoragerPrabhupadaDictionary()
  : inherited()
{
}

QStoragerPrabhupadaDictionary::~QStoragerPrabhupadaDictionary()
{
}

void QStoragerPrabhupadaDictionary::LoadFromStream( void *AObject, QDataStream &ST )
{
  QPrabhupadaDictionary *O = static_cast< QPrabhupadaDictionary* >( AObject );
  // 1
  O->LoadFromStream( ST );
}

void QStoragerPrabhupadaDictionary::SaveToStream( void *AObject, QDataStream &ST )
{
  QPrabhupadaDictionary *O = static_cast< QPrabhupadaDictionary* >( AObject );
  // 1
  O->SaveToStream( ST );
}
