/***********************************************************************
*
* Copyright (c) 2022-2022 Navadvipa Chandra dasa
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#ifndef QPrabhupadaDictionaryWindow_H
#define QPrabhupadaDictionaryWindow_H

#include <QtCore>
#include <QtGui>
#include <QPrabhupada.h>
#include <QPrabhupadaDictionary.h>

class QPrabhupadaDictionaryWindow : public QMainWindow {
  CS_OBJECT( QPrabhupadaDictionaryWindow )
  public:
    int m_SanskitHeaderSize = 50;
    int m_TranslateHeaderSize = 50;
    bool m_StartResize = false;

    QPrabhupadaDictionaryWindow()                                                    = delete;
    QPrabhupadaDictionaryWindow( const QPrabhupadaDictionaryWindow& A )              = delete;
    QPrabhupadaDictionaryWindow( QPrabhupadaDictionaryWindow&& A )                   = delete;
    QPrabhupadaDictionaryWindow( QPrabhupadaDictionary *APrabhupadaDictionary
                               , QWidget *parent = nullptr
                               , Qt::WindowFlags flags = Qt::WindowFlags() );
    QPrabhupadaDictionaryWindow& operator = ( const QPrabhupadaDictionaryWindow& A ) = delete;
    QPrabhupadaDictionaryWindow& operator = ( QPrabhupadaDictionaryWindow&& A )      = delete;
    ~QPrabhupadaDictionaryWindow();

    QPrabhupadaDictionary *m_PrabhupadaDictionary;
    QStorageKind m_StorageKind = QStorageKind::File;
    QStorage *m_Storage = nullptr;

    void PrepareDictionary();
    void FirstShow();
  private:
    using inherited = QMainWindow;

    void actionExit_Program();
    void actionFind();
    void actionCaseSensitive( bool Value );
    void actionRegularExpression( bool Value );
    void actionAutoPercentBegin( bool Value );
    void actionAutoPercentEnd( bool Value );
    void actionDelete();
    void actionInsert();
    void actionRemove_Duplicates();
    void actionWhats_This_mode();
    void actionGoToRow();
    void actionAbout();
    void actionDeleteAllBookmarks();
    void ActionSaveAllLetterToFile();
    void actionSet_Bookmark( unsigned short B );
    void actionSet_Bookmark_0();
    void actionSet_Bookmark_1();
    void actionSet_Bookmark_2();
    void actionSet_Bookmark_3();
    void actionSet_Bookmark_4();
    void actionSet_Bookmark_5();
    void actionSet_Bookmark_6();
    void actionSet_Bookmark_7();
    void actionSet_Bookmark_8();
    void actionSet_Bookmark_9();
    void actionGo_to_bookmark( unsigned short B );
    void actionGo_to_bookmark_0();
    void actionGo_to_bookmark_1();
    void actionGo_to_bookmark_2();
    void actionGo_to_bookmark_3();
    void actionGo_to_bookmark_4();
    void actionGo_to_bookmark_5();
    void actionGo_to_bookmark_6();
    void actionGo_to_bookmark_7();
    void actionGo_to_bookmark_8();
    void actionGo_to_bookmark_9();
    void PrepareLanguages();
    void LanguageIndexChanged( int Value );
    void LanguageUIIndexChanged( int Value );
    void DoOrderBy( QPrabhupadaDictionaryOrderBy Value );

    void CaseSensitiveChanged( bool Value );
    void RegularExpressionChanged( bool Value );
    void AutoPercentBeginChanged( bool Value );
    void AutoPercentEndChanged( bool Value );

    void PrabhupadaFilterSlovarChanged( QFilterSlovar Value );
    void PrabhupadaZakladkaChanged( QPrabhupadaZakladka Value );
    void DoGoToLine( int Value );
    void Connects();
    void Emits();
    void TablePrabhupadaCurrentRowChanged( const QModelIndex &current, const QModelIndex &previous );
    void TablePrabhupadaHeaderSectionResized( int logicalIndex, int oldSize, int newSize );
  protected:
    void changeEvent( QEvent *event ) override;
    void closeEvent( QCloseEvent *event ) override;
    void SpinBoxFontSizeChanged( int Value );
    virtual void FontSizeChanged( int Value );
    virtual void PrabhupadaTableResized();
    void resizeEvent( QResizeEvent *event ) override;
  public:
    QAction *m_actionFind;
    QAction *m_actionCaseSensitive;
    QAction *m_actionDelete;
    QAction *m_actionInsert;
    QAction *m_actionRemove_Duplicates;
    QAction *m_actionSet_Bookmark_0;
    QAction *m_actionSet_Bookmark_1;
    QAction *m_actionSet_Bookmark_2;
    QAction *m_actionSet_Bookmark_3;
    QAction *m_actionSet_Bookmark_4;
    QAction *m_actionSet_Bookmark_5;
    QAction *m_actionSet_Bookmark_6;
    QAction *m_actionSet_Bookmark_7;
    QAction *m_actionSet_Bookmark_8;
    QAction *m_actionSet_Bookmark_9;
    QAction *m_actionGo_to_bookmark_0;
    QAction *m_actionGo_to_bookmark_1;
    QAction *m_actionGo_to_bookmark_2;
    QAction *m_actionGo_to_bookmark_3;
    QAction *m_actionGo_to_bookmark_4;
    QAction *m_actionGo_to_bookmark_5;
    QAction *m_actionGo_to_bookmark_6;
    QAction *m_actionGo_to_bookmark_7;
    QAction *m_actionGo_to_bookmark_8;
    QAction *m_actionGo_to_bookmark_9;
    QAction *m_actionWhats_This_mode;
    QAction *m_actionGoToRow;
    QAction *m_actionAbout;
    QAction *m_ActionSaveAllLetterToFile;
    QAction *m_actionDeleteAllBookmarks;
    QAction *m_actionRegularExpression;
    QAction *m_actionAutoPercentBegin;
    QAction *m_actionAutoPercentEnd;
    QWidget *centralwidget;
    QVBoxLayout *vlPrabhuadaMain;
    QHBoxLayout *horizontalLayoutLanguage;
    QSpinBox *sbFontSize;
    QComboBox *ComboBoxLanguage;
    QComboBox *ComboBoxLanguageUI;
    QHBoxLayout *horizontalLayoutRow;
    QLineEdit *lineEditRowIndicator;
    QVBoxLayout *vlDictionary;
    QTableView *tbvPrabhupadaDictionary;
    QSplitter *splSanskritTranslate;
    QComboBox *ComboBoxSanskrit;
    QComboBox *ComboBoxTranslate;
    QMenuBar *mbPrabupadaDictionary;
    QMenu *menuAction;
    QMenu *menuSet_Bookmark;
    QMenu *menuGo_Bookmarks;
    QToolBar *tbPrabhupada;

    void setupUi();
    void retranslateUi();
  private :
    void RetranslateIcon();
};


class QStoragerPrabhupadaDictionaryWindow : public QStoragerMainWindow
{
  public:
    QStoragerPrabhupadaDictionaryWindow();
    virtual ~QStoragerPrabhupadaDictionaryWindow();
  private:
    using inherited = QStoragerMainWindow;
  public:
    virtual void LoadFromStream( void *AObject, QDataStream &ST ) override;
    virtual void SaveToStream(   void *AObject, QDataStream &ST ) override;
};

#endif
