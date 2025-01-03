/***********************************************************************
*
* Copyright (c) 2022-2022 Navadvipa Chandra dasa
*
* PrabhupadaDictionary is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include "QPrabhupadaDictionary.h"
#include <PrabhupadaDictionary_build_info.h>
#include <QPrabhupadaDictionaryWindow.h>
#include <QPrabhupadaGoToLineWindow.h>
#include <QPrabhupadaAboutWindow.h>
#include <QPrabhupada.h>
#include <QSaveFile>

QPrabhupadaDictionaryWindow::QPrabhupadaDictionaryWindow( QPrabhupadaDictionary *APrabhupadaDictionary
                                                        , QWidget *parent
                                                        , Qt::WindowFlags flags )
  : inherited( parent, flags )
  , m_PrabhupadaDictionary( APrabhupadaDictionary )
{
  setupUi();
  tbvPrabhupadaDictionary->verticalHeader()->hide();
  tbvPrabhupadaDictionary->setModel( m_PrabhupadaDictionary );
  Connects();
  #ifdef Q_OS_MAC
    setUnifiedTitleAndToolBarOnMac( true );
  #endif
}

void QPrabhupadaDictionaryWindow::Connects()
{
  QObject::connect( m_actionFind
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionFind );
  QObject::connect( m_actionCaseSensitive
                  , &QAction::toggled
                  , this
                  , &QPrabhupadaDictionaryWindow::actionCaseSensitive );
  QObject::connect( m_actionRegularExpression
                  , &QAction::toggled
                  , this
                  , &QPrabhupadaDictionaryWindow::actionRegularExpression );
  QObject::connect( m_actionAutoPercentBegin
                  , &QAction::toggled
                  , this
                  , &QPrabhupadaDictionaryWindow::actionAutoPercentBegin );
  QObject::connect( m_actionAutoPercentEnd
                  , &QAction::toggled
                  , this
                  , &QPrabhupadaDictionaryWindow::actionAutoPercentEnd );
  QObject::connect( m_actionDelete
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionDelete );
  QObject::connect( m_actionInsert
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionInsert );
  QObject::connect( m_actionRemove_Duplicates
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionRemove_Duplicates );
  QObject::connect( m_actionWhats_This_mode
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionWhats_This_mode );
  QObject::connect( m_actionGoToRow
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGoToRow );
  QObject::connect( m_actionAbout
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionAbout );
  QObject::connect( m_actionDeleteAllBookmarks
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionDeleteAllBookmarks );
  QObject::connect( m_ActionSaveAllLetterToFile
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::ActionSaveAllLetterToFile );
  QObject::connect( sbFontSize
                  , cs_mp_cast< int >( &QSpinBox::valueChanged )
                  , this
                  , &QPrabhupadaDictionaryWindow::SpinBoxFontSizeChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_FontSize
                  , &QEmitInt::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::FontSizeChanged );
  QObject::connect( ComboBoxLanguage
                  , cs_mp_cast< int >( &QComboBox::currentIndexChanged )
                  , &m_PrabhupadaDictionary->m_LanguageIndex
                  , &QLanguageIndex::SetValue );
  QObject::connect( ComboBoxLanguageUI
                  , cs_mp_cast< int >( &QComboBox::currentIndexChanged )
                  , &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SetValue );
  QObject::connect( &m_PrabhupadaDictionary->m_LanguageIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::LanguageIndexChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::LanguageUIIndexChanged );
  QObject::connect( tbvPrabhupadaDictionary->horizontalHeader()
                  , &QHeaderView::sortIndicatorChanged
                  , m_PrabhupadaDictionary
                  , &QPrabhupadaDictionary::sortByColumn );
  QObject::connect( &m_PrabhupadaDictionary->m_PrabhupadaOrder
                  , &QPrabhupadaOrder::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::DoOrderBy );
  QObject::connect( &m_PrabhupadaDictionary->m_CaseSensitive
                  , &QEmitBool::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::CaseSensitiveChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_RegularExpression
                  , &QEmitBool::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::RegularExpressionChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_AutoPercentBegin
                  , &QEmitBool::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::AutoPercentBeginChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_AutoPercentEnd
                  , &QEmitBool::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::AutoPercentEndChanged );
  QObject::connect( &m_PrabhupadaDictionary->m_PrabhupadaFilterSlovar
                  , &QPrabhupadaFilterSlovar::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::PrabhupadaFilterSlovarChanged );
  QObject::connect( tbvPrabhupadaDictionary->selectionModel()
                  , &QItemSelectionModel::currentRowChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::TablePrabhupadaCurrentRowChanged );
  QObject::connect( tbvPrabhupadaDictionary->horizontalHeader()
                  , &QHeaderView::sectionResized
                  , this
                  , &QPrabhupadaDictionaryWindow::TablePrabhupadaHeaderSectionResized );
  QObject::connect( m_actionSet_Bookmark_0
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_0 );
  QObject::connect( m_actionSet_Bookmark_1
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_1 );
  QObject::connect( m_actionSet_Bookmark_2
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_2 );
  QObject::connect( m_actionSet_Bookmark_3
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_3 );
  QObject::connect( m_actionSet_Bookmark_4
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_4 );
  QObject::connect( m_actionSet_Bookmark_5
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_5 );
  QObject::connect( m_actionSet_Bookmark_6
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_6 );
  QObject::connect( m_actionSet_Bookmark_7
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_7 );
  QObject::connect( m_actionSet_Bookmark_8
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_8 );
  QObject::connect( m_actionSet_Bookmark_9
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionSet_Bookmark_9 );
  QObject::connect( m_actionGo_to_bookmark_0
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_0 );
  QObject::connect( m_actionGo_to_bookmark_1
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_1 );
  QObject::connect( m_actionGo_to_bookmark_2
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_2 );
  QObject::connect( m_actionGo_to_bookmark_3
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_3 );
  QObject::connect( m_actionGo_to_bookmark_4
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_4 );
  QObject::connect( m_actionGo_to_bookmark_5
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_5 );
  QObject::connect( m_actionGo_to_bookmark_6
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_6 );
  QObject::connect( m_actionGo_to_bookmark_7
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_7 );
  QObject::connect( m_actionGo_to_bookmark_8
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_8 );
  QObject::connect( m_actionGo_to_bookmark_9
                  , &QAction::triggered
                  , this
                  , &QPrabhupadaDictionaryWindow::actionGo_to_bookmark_9 );
  QObject::connect( &m_PrabhupadaDictionary->m_PrabhupadaZakladka
                  , &QEmitPrabhupadaZakladka::SignalValueChanged
                  , this
                  , &QPrabhupadaDictionaryWindow::PrabhupadaZakladkaChanged );
}

void QPrabhupadaDictionaryWindow::Emits()
{
  m_PrabhupadaDictionary->m_LanguageIndex.EmitValueChanged();
  m_PrabhupadaDictionary->m_LanguageUIIndex.EmitValueChanged();
  m_PrabhupadaDictionary->m_FontSize.EmitValueChanged();
  m_PrabhupadaDictionary->m_PrabhupadaOrder.EmitValueChanged();
  m_PrabhupadaDictionary->m_CaseSensitive.EmitValueChanged();
  m_PrabhupadaDictionary->m_RegularExpression.EmitValueChanged();
  m_PrabhupadaDictionary->m_AutoPercentBegin.EmitValueChanged();
  m_PrabhupadaDictionary->m_AutoPercentEnd.EmitValueChanged();
  m_PrabhupadaDictionary->m_PrabhupadaFilterSlovar.EmitValueChanged();
  tbvPrabhupadaDictionary->setFocus( Qt::ActiveWindowFocusReason );
}

QPrabhupadaDictionaryWindow::~QPrabhupadaDictionaryWindow()
{
}

void QPrabhupadaDictionaryWindow::SpinBoxFontSizeChanged( int Value )
{
  m_PrabhupadaDictionary->m_FontSize.SetValue( Value );
}

void QPrabhupadaDictionaryWindow::FontSizeChanged( int Value )
{
  sbFontSize->setValue( Value );
  QFont F = ComboBoxSanskrit->font();
  F.setPointSize( Value );
  ComboBoxSanskrit->setFont( F );
  ComboBoxTranslate->setFont( F );
  tbvPrabhupadaDictionary->setFont( F );

  QHeaderView *verticalHeader = tbvPrabhupadaDictionary->verticalHeader();
  //verticalHeader->setSectionResizeMode( QHeaderView::Fixed );
  QFontMetrics FM( F );
  verticalHeader->setDefaultSectionSize( FM.height() );
}

void QPrabhupadaDictionaryWindow::actionFind()
{
  QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_PrabhupadaDictionary->m_LanguageVector[ (std::size_t)m_PrabhupadaDictionary->m_LanguageIndex.m_Value ] );

  QFilterSlovar& FS = YI->m_PrabhupadaZakladka.m_FilterSlovar;

  FS.m_PrabhupadaFindOptions = QPrabhupadaFindOptions( m_PrabhupadaDictionary->m_CaseSensitive.m_Value
                                                     , m_PrabhupadaDictionary->m_RegularExpression.m_Value
                                                     , m_PrabhupadaDictionary->m_AutoPercentBegin.m_Value
                                                     , m_PrabhupadaDictionary->m_AutoPercentEnd.m_Value );
  FS.SetSanskrit ( ComboBoxSanskrit ->currentText() );
  FS.SetTranslate( ComboBoxTranslate->currentText() );

  m_PrabhupadaDictionary->m_PrabhupadaFilterSlovar.SetValue( FS );

  PrepareHistoryComboBox( ComboBoxSanskrit );
  PrepareHistoryComboBox( ComboBoxTranslate );
}

void QPrabhupadaDictionaryWindow::actionCaseSensitive( bool Value )
{
  m_PrabhupadaDictionary->m_CaseSensitive.SetValue( Value );
}

void QPrabhupadaDictionaryWindow::actionRegularExpression( bool Value )
{
  m_PrabhupadaDictionary->m_RegularExpression.SetValue( Value );
}

void QPrabhupadaDictionaryWindow::actionAutoPercentBegin( bool Value )
{
  m_PrabhupadaDictionary->m_AutoPercentBegin.SetValue( Value );
}

void QPrabhupadaDictionaryWindow::actionAutoPercentEnd( bool Value )
{
  m_PrabhupadaDictionary->m_AutoPercentEnd.SetValue( Value );
}

void QPrabhupadaDictionaryWindow::actionDelete()
{
}

void QPrabhupadaDictionaryWindow::actionInsert()
{
}

void QPrabhupadaDictionaryWindow::actionRemove_Duplicates()
{
}

void QPrabhupadaDictionaryWindow::actionWhats_This_mode()
{
  if ( QWhatsThis::inWhatsThisMode() ) {
    QWhatsThis::leaveWhatsThisMode();
  } else {
    QWhatsThis::enterWhatsThisMode();
  }

  QString A[3];
  A[ 0 ] = "рубль";
  A[ 1 ] = "рубля";
  A[ 2 ] = "рублей";
  QString W = StringNumberToWords( ComboBoxSanskrit->currentText(), QGender::Male, A, true );
  PrabhupadaLog( W );
  PrabhupadaMessage( W );
}

void QPrabhupadaDictionaryWindow::actionGoToRow()
{
  QPrabhupadaGoToLineDialog APrabhupadaGoToLineDialog( this, Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint );

  QObject::connect( &APrabhupadaGoToLineDialog
                  , &QPrabhupadaGoToLineDialog::SignalGoToLine
                  , this
                  , &QPrabhupadaDictionaryWindow::DoGoToLine );

  StoragerDialogExec< QStoragerPrabhupadaGoToLineDialog >( &APrabhupadaGoToLineDialog, m_Storage, QStorageKind::Memory );
}

void QPrabhupadaDictionaryWindow::actionAbout()
{
  QPrabhupadaAboutDialog APrabhupadaAboutDialog( this, Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint );

  StoragerDialogExec< QStoragerPrabhupadaAboutDialog >( &APrabhupadaAboutDialog, m_Storage, QStorageKind::DB );
}

void QPrabhupadaDictionaryWindow::actionDeleteAllBookmarks()
{
  QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_PrabhupadaDictionary->m_LanguageVector[ (std::size_t)m_PrabhupadaDictionary->m_LanguageIndex.m_Value ] );
  YI->m_PrabhupadaZakladkaMap.clear();
}

void QPrabhupadaDictionaryWindow::ActionSaveAllLetterToFile()
{
  QMessageBox::StandardButton reply;

  reply = QMessageBox::question( this
                               , tr( "Пожалуйста, внимание!" )
                               , tr( "Собираем все буквы в файл?" )
                               , QMessageBox::Yes | QMessageBox::No );

  if ( reply == QMessageBox::Yes ) {
    QString S, SB;
    std::set< QChar > Set;
    std::size_t L = m_PrabhupadaDictionary->m_PrabhupadaSlovarVector.size();
    QString::size_type SL;
    QSanskritTranslate* sp;

    for ( int i = 0; i < L; ++i ) {
      sp = m_PrabhupadaDictionary->m_PrabhupadaSlovarVector[ i ];
      S = sp->m_Sanskrit + sp->m_Translate;
      SL = S.size();
      for ( int j = 0; j < SL; ++j ) {
        Set.insert( S[ j ] );
      }
    }

    QSaveFile ASaveFile = QSaveFile( "AllPrabhupadaLetter.txt" );
    QDataStream  AStream = QDataStream( &ASaveFile );
    ASaveFile.open( QIODevice::WriteOnly );

    for ( std::set< QChar >::iterator I = Set.begin(); I != Set.end(); ++I ) {
      SB.append( (*I) );
      SB += "\t";
      SB.append( (*I) );
      SB += "\n";
    }
    AStream << SB;
    ASaveFile.commit();
  }
}

void QPrabhupadaDictionaryWindow::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    retranslateUi();
  }

  inherited::changeEvent( event );
}

void QPrabhupadaDictionaryWindow::closeEvent( QCloseEvent *event )
{
  if ( m_Storage ) {
    QStoragerPrabhupadaDictionary*       AStoragerPrabhupadaDictionary       = new QStoragerPrabhupadaDictionary();
    QStoragerLanguageIndex*              AStoragerLanguageIndex              = new QStoragerLanguageIndex();
    QStoragerLanguageVector*             AStoragerLanguageVector             = new QStoragerLanguageVector();
    QStoragerPrabhupadaDictionaryWindow* AStoragerPrabhupadaDictionaryWindow = new QStoragerPrabhupadaDictionaryWindow();

    m_Storage->SaveObject( m_PrabhupadaDictionary,                     QStorageKind::DB,   AStoragerPrabhupadaDictionary );
    m_Storage->SaveObject( &m_PrabhupadaDictionary->m_LanguageUIIndex, QStorageKind::File, AStoragerLanguageIndex );
    m_Storage->SaveObject( &m_PrabhupadaDictionary->m_LanguageVector,  QStorageKind::File, AStoragerLanguageVector, "m_LanguageVector.ini" );
    m_Storage->SaveObject( this,                                       m_StorageKind,      AStoragerPrabhupadaDictionaryWindow );

    delete AStoragerPrabhupadaDictionary;
    delete AStoragerLanguageVector;
    delete AStoragerLanguageIndex;
    delete AStoragerPrabhupadaDictionaryWindow;
  }
  inherited::closeEvent( event );
}

void QPrabhupadaDictionaryWindow::actionExit_Program()
{
  close();
}

void QPrabhupadaDictionaryWindow::PrepareDictionary()
{
  m_PrabhupadaDictionary->PrepareLanguageAndMaxID();
  PrepareLanguages();
}

void QPrabhupadaDictionaryWindow::PrepareLanguages()
{
  m_PrabhupadaDictionary->m_LanguageIndex.PrepareComboBox( ComboBoxLanguage );
  m_PrabhupadaDictionary->m_LanguageUIIndex.PrepareComboBox( ComboBoxLanguageUI );
}

void QPrabhupadaDictionaryWindow::LanguageIndexChanged( int Value )
{
  ComboBoxLanguage->setCurrentIndex( Value );
}

void QPrabhupadaDictionaryWindow::LanguageUIIndexChanged( int Value )
{
  ComboBoxLanguageUI->setCurrentIndex( Value );
}

void QPrabhupadaDictionaryWindow::DoOrderBy( QPrabhupadaDictionaryOrderBy Value )
{
  QHeaderView* HV = tbvPrabhupadaDictionary->horizontalHeader();
  switch ( Value ) {
  case QPrabhupadaDictionaryOrderBy::SanskritIncreasing :
    HV->setSortIndicator( 0, Qt::AscendingOrder );
    break;
  case QPrabhupadaDictionaryOrderBy::SanskritDecreasing :
    HV->setSortIndicator( 0, Qt::DescendingOrder );
    break;
  case QPrabhupadaDictionaryOrderBy::TranslateIncreasing :
    HV->setSortIndicator( 1, Qt::AscendingOrder );
    break;
  case QPrabhupadaDictionaryOrderBy::TranslateDecreasing :
    HV->setSortIndicator( 1, Qt::DescendingOrder );
    break;
  }
}

void QPrabhupadaDictionaryWindow::CaseSensitiveChanged( bool Value )
{
  m_actionCaseSensitive->setChecked( Value );
}

void QPrabhupadaDictionaryWindow::RegularExpressionChanged( bool Value )
{
  m_actionRegularExpression->setChecked( Value );

  m_actionCaseSensitive    ->setEnabled( Value );
  m_actionAutoPercentBegin ->setEnabled( !Value );
  m_actionAutoPercentEnd   ->setEnabled( !Value );
}

void QPrabhupadaDictionaryWindow::AutoPercentBeginChanged( bool Value )
{
  m_actionAutoPercentBegin->setChecked( Value );
}

void QPrabhupadaDictionaryWindow::AutoPercentEndChanged( bool Value )
{
  m_actionAutoPercentEnd->setChecked( Value );
}

void QPrabhupadaDictionaryWindow::PrabhupadaFilterSlovarChanged( QFilterSlovar Value )
{
  m_actionCaseSensitive    ->setChecked( Value.m_PrabhupadaFindOptions.m_CaseSensitive );
  m_actionRegularExpression->setChecked( Value.m_PrabhupadaFindOptions.m_RegularExpression );
  m_actionAutoPercentBegin ->setChecked( Value.m_PrabhupadaFindOptions.m_AutoPercentBegin );
  m_actionAutoPercentEnd   ->setChecked( Value.m_PrabhupadaFindOptions.m_AutoPercentEnd );

  if ( Value.m_Sanskrit != ComboBoxSanskrit->currentText() ) {
    ComboBoxSanskrit ->setCurrentText( Value.m_Sanskrit );
  }
  if ( Value.m_Translate != ComboBoxTranslate->currentText() ) {
    ComboBoxTranslate->setCurrentText( Value.m_Translate );
  }
  QModelIndex I = tbvPrabhupadaDictionary->currentIndex();
  emit tbvPrabhupadaDictionary->selectionModel()->currentRowChanged( I, I );
}

void QPrabhupadaDictionaryWindow::DoGoToLine( int Value )
{
  QModelIndex I = m_PrabhupadaDictionary->index( Value - 1, tbvPrabhupadaDictionary->currentIndex().column() );
  tbvPrabhupadaDictionary->setCurrentIndex( I );
  tbvPrabhupadaDictionary->scrollTo( I );
}

void QPrabhupadaDictionaryWindow::TablePrabhupadaCurrentRowChanged( const QModelIndex &current, const QModelIndex &/*previous*/ )
{
  int R = current.row() + 1;
  std::size_t A;
  if ( m_PrabhupadaDictionary->m_FilterSlovarIsEmpty ) {
    A = m_PrabhupadaDictionary->m_PrabhupadaSlovarVector.size();
  } else {
    A = m_PrabhupadaDictionary->m_PrabhupadaSlovarVector.m_SearchCount;
  }

  if ( R > 0 ) {
    QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_PrabhupadaDictionary->m_LanguageVector[ (std::size_t)m_PrabhupadaDictionary->m_LanguageIndex.m_Value ] );

    YI->m_PrabhupadaZakladka.m_RowNum    = R - 1;
    YI->m_PrabhupadaZakladka.m_ColumnNum = current.column();
  }

  QString S = QString::number( R ) + " / " + QString::number( A );
  lineEditRowIndicator->setText( S );
}

void QPrabhupadaDictionaryWindow::PrabhupadaTableResized()
{
  QTableView *TV = tbvPrabhupadaDictionary;
  QScrollBar *SB = TV->verticalScrollBar();
  int SBW = 0;

  if ( SB ) {
    SBW = SB->width() + 2;
  }

  int WidthNew = TV->width()
    , WidthOld = m_SanskitHeaderSize + m_TranslateHeaderSize;

  if ( WidthNew > SBW )
    WidthNew -= SBW;

  TV->setColumnWidth( 0, m_SanskitHeaderSize   * WidthNew / WidthOld );
  TV->setColumnWidth( 1, m_TranslateHeaderSize * WidthNew / WidthOld );
}

void QPrabhupadaDictionaryWindow::resizeEvent( QResizeEvent *event )
{
  if ( m_StartResize ) {
    PrabhupadaTableResized();
  }
  inherited::resizeEvent( event );
}

void QPrabhupadaDictionaryWindow::TablePrabhupadaHeaderSectionResized( int /*logicalIndex*/, int /*oldSize*/, int /*newSize*/ )
{
  if ( m_StartResize ) {
    QHeaderView *HV = tbvPrabhupadaDictionary->horizontalHeader();

    m_SanskitHeaderSize = HV->sectionSize( 0 );
    m_TranslateHeaderSize = HV->sectionSize( 1 );
  }
}

void QPrabhupadaDictionaryWindow::FirstShow()
{
  Emits();
  show();
  m_StartResize = true;
  TablePrabhupadaHeaderSectionResized( 0, 0, 0 );
  PrabhupadaTableResized();
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark( unsigned short B )
{
  QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_PrabhupadaDictionary->m_LanguageVector[ (std::size_t)m_PrabhupadaDictionary->m_LanguageIndex.m_Value ] );

  QPrabhupadaZakladkaMap::iterator I = YI->m_PrabhupadaZakladkaMap.find( B );
  QModelIndex CI = tbvPrabhupadaDictionary->currentIndex();
  int ARowNum  = CI.row()
    , AColumnNum = CI.column();
  if ( I == YI->m_PrabhupadaZakladkaMap.end() ) {
    YI->m_PrabhupadaZakladkaMap[ B ] = QPrabhupadaZakladka( ARowNum, AColumnNum, m_PrabhupadaDictionary->m_PrabhupadaFilterSlovar.m_Value );
  } else {
    (*I).second.m_RowNum       = ARowNum;
    (*I).second.m_ColumnNum    = AColumnNum;
    (*I).second.m_FilterSlovar = m_PrabhupadaDictionary->m_PrabhupadaFilterSlovar.m_Value;
  }
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_0()
{
  actionSet_Bookmark( 0 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_1()
{
  actionSet_Bookmark( 1 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_2()
{
  actionSet_Bookmark( 2 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_3()
{
  actionSet_Bookmark( 3 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_4()
{
  actionSet_Bookmark( 4 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_5()
{
  actionSet_Bookmark( 5 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_6()
{
  actionSet_Bookmark( 6 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_7()
{
  actionSet_Bookmark( 7 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_8()
{
  actionSet_Bookmark( 8 );
}

void QPrabhupadaDictionaryWindow::actionSet_Bookmark_9()
{
  actionSet_Bookmark( 9 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark( unsigned short B )
{
  QLanguageInfoPrabhupadaDictionary* YI = static_cast< QLanguageInfoPrabhupadaDictionary* >( m_PrabhupadaDictionary->m_LanguageVector[ (std::size_t)m_PrabhupadaDictionary->m_LanguageIndex.m_Value ] );

  QPrabhupadaZakladkaMap::iterator ZI = YI->m_PrabhupadaZakladkaMap.find( B );
  if ( ZI != YI->m_PrabhupadaZakladkaMap.end() ) {
    QPrabhupadaZakladka& PrabhupadaZakladka = YI->m_PrabhupadaZakladkaMap[ B ];
    // We are searching for words!
    m_PrabhupadaDictionary->m_PrabhupadaFilterSlovar.SetValue( PrabhupadaZakladka.m_FilterSlovar );
    // We are navigating by row and column number!
    QModelIndex I = m_PrabhupadaDictionary->index( PrabhupadaZakladka.m_RowNum
                                                 , PrabhupadaZakladka.m_ColumnNum );
    tbvPrabhupadaDictionary->setCurrentIndex( I );
    tbvPrabhupadaDictionary->scrollTo( I );
  }
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_0()
{
  actionGo_to_bookmark( 0 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_1()
{
  actionGo_to_bookmark( 1 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_2()
{
  actionGo_to_bookmark( 2 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_3()
{
  actionGo_to_bookmark( 3 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_4()
{
  actionGo_to_bookmark( 4 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_5()
{
  actionGo_to_bookmark( 5 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_6()
{
  actionGo_to_bookmark( 6 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_7()
{
  actionGo_to_bookmark( 7 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_8()
{
  actionGo_to_bookmark( 8 );
}

void QPrabhupadaDictionaryWindow::actionGo_to_bookmark_9()
{
  actionGo_to_bookmark( 9 );
}

void QPrabhupadaDictionaryWindow::PrabhupadaZakladkaChanged( QPrabhupadaZakladka Value )
{
  // We are navigating by row and column number!
  QModelIndex I = m_PrabhupadaDictionary->index( Value.m_RowNum
                                               , Value.m_ColumnNum );
  tbvPrabhupadaDictionary->setCurrentIndex( I );
  tbvPrabhupadaDictionary->scrollTo( I );
}

void QPrabhupadaDictionaryWindow::RetranslateIcon()
{
  QIcon AIcon;
  QString ALanguage;

  std::size_t L  = m_PrabhupadaDictionary->m_LanguageVector.size()
            , UI = (std::size_t)m_PrabhupadaDictionary->m_LanguageUIIndex.m_Value;
  if ( UI >= 0 && L > UI ) {
    QLanguageInfo* YI = m_PrabhupadaDictionary->m_LanguageVector[ UI ];
    ALanguage = YI->m_Language;
  }

  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "PrabhupadaDictionary.ico"
                    , nullptr
                    , true, ALanguage );
  setWindowIcon( AIcon );

  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "Find.png"
                    , m_actionFind
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "CaseSensitive.png"
                    , m_actionCaseSensitive
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "Delete.png"
                    , m_actionDelete
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "Insert.png"
                    , m_actionInsert
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "RemoveDuplicates.png"
                    , m_actionRemove_Duplicates
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "WhatsThis.png"
                    , m_actionWhats_This_mode
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "GoToRow.png"
                    , m_actionGoToRow
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "About.png"
                    , m_actionAbout
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "SaveBukva.png"
                    , m_ActionSaveAllLetterToFile
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "DeleteAllBookmarks.png"
                    , m_actionDeleteAllBookmarks
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "RegularExpression.png"
                    , m_actionRegularExpression
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "AutoPercentBegin.png"
                    , m_actionAutoPercentBegin
                    , true, ALanguage );
  SetRetranslateIcon( AIcon
                    , QPrabhupadaDictionary::PrabhupadaDictionaryImages, "AutoPercentEnd.png"
                    , m_actionAutoPercentEnd
                    , true, ALanguage );
}

void QPrabhupadaDictionaryWindow::setupUi()
{
  if ( objectName().isEmpty() ) {
    setObjectName( "QPrabhupadaDictionaryWindow" );
  }
  resize( 320, 480 );
  setMinimumSize( QSize( 320, 480 ) );
  m_actionFind = new QAction( this );

  m_actionCaseSensitive = new QAction( this );
  m_actionCaseSensitive->setCheckable( true );

  m_actionDelete = new QAction( this );

  m_actionInsert = new QAction( this );

  m_actionRemove_Duplicates = new QAction( this );

  m_actionSet_Bookmark_0 = new QAction( this );
  m_actionSet_Bookmark_1 = new QAction( this );
  m_actionSet_Bookmark_2 = new QAction( this );
  m_actionSet_Bookmark_3 = new QAction( this );
  m_actionSet_Bookmark_4 = new QAction( this );
  m_actionSet_Bookmark_5 = new QAction( this );
  m_actionSet_Bookmark_6 = new QAction( this );
  m_actionSet_Bookmark_7 = new QAction( this );
  m_actionSet_Bookmark_8 = new QAction( this );
  m_actionSet_Bookmark_9 = new QAction( this );

  m_actionGo_to_bookmark_0 = new QAction( this );
  m_actionGo_to_bookmark_1 = new QAction( this );
  m_actionGo_to_bookmark_2 = new QAction( this );
  m_actionGo_to_bookmark_3 = new QAction( this );
  m_actionGo_to_bookmark_4 = new QAction( this );
  m_actionGo_to_bookmark_5 = new QAction( this );
  m_actionGo_to_bookmark_6 = new QAction( this );
  m_actionGo_to_bookmark_7 = new QAction( this );
  m_actionGo_to_bookmark_8 = new QAction( this );
  m_actionGo_to_bookmark_9 = new QAction( this );

  m_actionWhats_This_mode = new QAction( this );

  m_actionGoToRow = new QAction( this );

  m_actionAbout = new QAction( this );

  m_ActionSaveAllLetterToFile = new QAction( this );

  m_actionDeleteAllBookmarks = new QAction( this );

  m_actionRegularExpression = new QAction( this );
  m_actionRegularExpression->setCheckable( true );

  m_actionAutoPercentBegin = new QAction( this );
  m_actionAutoPercentBegin->setCheckable( true );

  m_actionAutoPercentEnd = new QAction( this );
  m_actionAutoPercentEnd->setCheckable( true );

  centralwidget = new QWidget( this );

  vlPrabhuadaMain = new QVBoxLayout(centralwidget);

  horizontalLayoutLanguage = new QHBoxLayout();

  sbFontSize = new QSpinBox(centralwidget);
  sbFontSize->setFocusPolicy( Qt::WheelFocus );
  sbFontSize->setAlignment( Qt::AlignCenter );
  sbFontSize->setMinimum( 14 );
  sbFontSize->setMaximum( 24 );
  sbFontSize->setValue( 14 );

  horizontalLayoutLanguage->addWidget( sbFontSize );

  ComboBoxLanguage = new QComboBox( centralwidget );
  ComboBoxLanguage->setFocusPolicy( Qt::WheelFocus );

  horizontalLayoutLanguage->addWidget( ComboBoxLanguage );

  ComboBoxLanguageUI = new QComboBox( centralwidget );
  ComboBoxLanguageUI->setFocusPolicy( Qt::WheelFocus );

  horizontalLayoutLanguage->addWidget( ComboBoxLanguageUI );

  horizontalLayoutLanguage->setStretch( 0, 1 );
  horizontalLayoutLanguage->setStretch( 1, 3 );
  horizontalLayoutLanguage->setStretch( 2, 3 );

  vlPrabhuadaMain->addLayout( horizontalLayoutLanguage );

  horizontalLayoutRow = new QHBoxLayout();

  lineEditRowIndicator = new QLineEdit(centralwidget);
  lineEditRowIndicator->setFocusPolicy( Qt::NoFocus );
  lineEditRowIndicator->setAlignment( Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter );
  lineEditRowIndicator->setReadOnly( true );

  horizontalLayoutRow->addWidget( lineEditRowIndicator );

  vlPrabhuadaMain->addLayout( horizontalLayoutRow );

  vlDictionary = new QVBoxLayout();

  tbvPrabhupadaDictionary = new QTableView( centralwidget );

  QFont font;
  font.setFamily( { QString::fromUtf8( "Gaura Times" ) } );
  font.setPointSize( 14 );

  tbvPrabhupadaDictionary->setFont( font );
  tbvPrabhupadaDictionary->setTabKeyNavigation( false );
  tbvPrabhupadaDictionary->setSortingEnabled( true );
  tbvPrabhupadaDictionary->horizontalHeader()->setCascadingSectionResizes( false );
  tbvPrabhupadaDictionary->horizontalHeader()->setStretchLastSection( false );

  vlDictionary->addWidget(tbvPrabhupadaDictionary);

  splSanskritTranslate = new QSplitter( centralwidget );
  splSanskritTranslate->setOrientation( Qt::Horizontal );
  splSanskritTranslate->setChildrenCollapsible( false );

  ComboBoxSanskrit = new QComboBox(splSanskritTranslate);
  ComboBoxSanskrit->setFont(font);
  ComboBoxSanskrit->setEditable( true );

  splSanskritTranslate->addWidget( ComboBoxSanskrit );

  ComboBoxTranslate = new QComboBox( splSanskritTranslate );
  ComboBoxTranslate->setFont( font );
  ComboBoxTranslate->setEditable( true );

  splSanskritTranslate->addWidget( ComboBoxTranslate );

  vlDictionary->addWidget( splSanskritTranslate );

  vlPrabhuadaMain->addLayout( vlDictionary );

  setCentralWidget( centralwidget );

  mbPrabupadaDictionary = new QMenuBar( this );
  mbPrabupadaDictionary->setGeometry( QRect( 0, 0, 320, 22 ) );

  QSizePolicy sizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
  sizePolicy.setHorizontalStretch( 0 );
  sizePolicy.setVerticalStretch( 0 );
  sizePolicy.setHeightForWidth(mbPrabupadaDictionary->sizePolicy().hasHeightForWidth());

  mbPrabupadaDictionary->setSizePolicy( sizePolicy );

  menuAction = new QMenu( mbPrabupadaDictionary );

  menuSet_Bookmark = new QMenu( mbPrabupadaDictionary );

  menuGo_Bookmarks = new QMenu( mbPrabupadaDictionary );

  setMenuBar( mbPrabupadaDictionary );

  tbPrabhupada = new QToolBar( this );
  tbPrabhupada->setOrientation( Qt::Horizontal );
  tbPrabhupada->setToolButtonStyle( Qt::ToolButtonFollowStyle );
  tbPrabhupada->setFloatable( true );

  addToolBar( Qt::TopToolBarArea, tbPrabhupada );

  QWidget::setTabOrder( sbFontSize, ComboBoxLanguage );
  QWidget::setTabOrder( ComboBoxLanguage, ComboBoxLanguageUI );
  QWidget::setTabOrder( ComboBoxLanguageUI, lineEditRowIndicator );
  QWidget::setTabOrder( lineEditRowIndicator, tbvPrabhupadaDictionary );
  QWidget::setTabOrder( tbvPrabhupadaDictionary, ComboBoxSanskrit );
  QWidget::setTabOrder( ComboBoxSanskrit, ComboBoxTranslate );

  mbPrabupadaDictionary->addAction( menuAction->menuAction() );
  mbPrabupadaDictionary->addAction( menuSet_Bookmark->menuAction() );
  mbPrabupadaDictionary->addAction( menuGo_Bookmarks->menuAction() );

  menuAction->addAction( m_actionFind );
  menuAction->addAction( m_actionCaseSensitive );
  menuAction->addAction( m_actionDelete );
  menuAction->addAction( m_actionInsert );
  menuAction->addAction( m_actionRemove_Duplicates );
  menuAction->addAction( m_actionWhats_This_mode );
  menuAction->addAction( m_actionGoToRow );
  menuAction->addAction( m_actionAbout );
  menuAction->addAction( m_ActionSaveAllLetterToFile );
  menuAction->addAction( m_actionRegularExpression );
  menuAction->addAction( m_actionAutoPercentBegin );
  menuAction->addAction( m_actionAutoPercentEnd );

  menuSet_Bookmark->addAction( m_actionSet_Bookmark_0 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_1 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_2 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_3 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_4 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_5 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_6 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_7 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_8 );
  menuSet_Bookmark->addAction( m_actionSet_Bookmark_9 );
  menuSet_Bookmark->addAction( m_actionDeleteAllBookmarks );

  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_0 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_1 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_2 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_3 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_4 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_5 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_6 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_7 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_8 );
  menuGo_Bookmarks->addAction( m_actionGo_to_bookmark_9 );

  tbPrabhupada->addAction( m_actionDelete );
  tbPrabhupada->addAction( m_actionFind );
  tbPrabhupada->addAction( m_actionInsert );
  tbPrabhupada->addAction( m_actionWhats_This_mode );
  tbPrabhupada->addAction( m_actionCaseSensitive );
  tbPrabhupada->addAction( m_actionRemove_Duplicates );
  tbPrabhupada->addAction( m_actionGoToRow );
  tbPrabhupada->addAction( m_actionAbout );
  tbPrabhupada->addAction( m_actionRegularExpression );
  tbPrabhupada->addAction( m_actionAutoPercentBegin );
  tbPrabhupada->addAction( m_actionAutoPercentEnd );
  tbPrabhupada->addAction( m_actionDeleteAllBookmarks );

  retranslateUi();
} // setupUi

void QPrabhupadaDictionaryWindow::retranslateUi()
{
  setWindowTitle( tr( "Словарь Шрилы Прабхупады" ) );
  #if !QT_NO_WHATSTHIS
    setWhatsThis( tr( "Словарь Его Божественной Милости основателя-ачарьи Международного Общества сознания Кришны Шри Шримад Абхая Чаранаравидны Бхактиведанты Свами Прабхупады! Познакомиться с его книгами можно на сайте vedabase.io" ) );
  #endif // !QT_NO_WHATSTHIS

  m_actionFind->setText( tr( "&Найти" ) );
  #if !QT_NO_SHORTCUT
    m_actionFind->setShortcut( tr( "Return" ) );
  #endif // !QT_NO_SHORTCUT

  m_actionCaseSensitive->setText( tr( "&Различать регистр" ) );

  m_actionDelete->setText( tr( "&Удалить" ) );
  #if !QT_NO_SHORTCUT
    m_actionDelete->setShortcut( tr( "Ctrl+Del" ) );
  #endif // !QT_NO_SHORTCUT

  m_actionInsert->setText( tr( "&Вставить" ) );
  #if !QT_NO_SHORTCUT
    m_actionInsert->setShortcut( tr( "Ctrl+Ins" ) );
  #endif // !QT_NO_SHORTCUT

  m_actionRemove_Duplicates->setText( tr( "Удалить &дубликаты" ) );

  m_actionSet_Bookmark_0->setText( tr( "Установить закладку &0" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_0->setShortcut( tr( "Ctrl+0" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_1->setText( tr( "Установить закладку &1" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_1->setShortcut( tr( "Ctrl+1" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_2->setText( tr( "Установить закладку &2" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_2->setShortcut( tr( "Ctrl+2" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_3->setText( tr( "Установить закладку &3" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_3->setShortcut( tr( "Ctrl+3" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_4->setText( tr( "Установить закладку &4" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_4->setShortcut( tr( "Ctrl+4" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_5->setText( tr( "Установить закладку &5" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_5->setShortcut( tr( "Ctrl+5" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_6->setText( tr( "Установить закладку &6" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_6->setShortcut( tr( "Ctrl+6" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_7->setText( tr( "Установить закладку &7" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_7->setShortcut( tr( "Ctrl+7" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_8->setText( tr( "Установить закладку &8" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_8->setShortcut( tr( "Ctrl+8" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionSet_Bookmark_9->setText( tr( "Установить закладку &9" ) );
  #if !QT_NO_SHORTCUT
    m_actionSet_Bookmark_9->setShortcut( tr( "Ctrl+9" ) );
  #endif // !QT_NO_SHORTCUT

  m_actionGo_to_bookmark_0->setText( tr( "К закладке &0" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_0->setShortcut( tr( "Alt+0" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_1->setText( tr( "К закладке &1" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_1->setShortcut( tr( "Alt+1" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_2->setText( tr( "К закладке &2" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_2->setShortcut( tr( "Alt+2" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_3->setText( tr( "К закладке &3" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_3->setShortcut( tr( "Alt+3" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_4->setText( tr( "К закладке &4" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_4->setShortcut( tr( "Alt+4" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_5->setText( tr( "К закладке &5" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_5->setShortcut( tr( "Alt+5" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_6->setText( tr( "К закладке &6" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_6->setShortcut( tr( "Alt+6" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_7->setText( tr( "К закладке &7" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_7->setShortcut( tr( "Alt+7" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_8->setText( tr( "К закладке &8" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_8->setShortcut( tr( "Alt+8" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGo_to_bookmark_9->setText( tr( "К закладке &9" ) );
  #if !QT_NO_SHORTCUT
    m_actionGo_to_bookmark_9->setShortcut( tr( "Alt+9" ) );
  #endif // !QT_NO_SHORTCUT

  m_actionWhats_This_mode->setText( tr( "&Режим вопроса" ) );
  #if !QT_NO_SHORTCUT
    m_actionWhats_This_mode->setShortcut( tr( "Shift+F1" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionGoToRow->setText( tr( "&Перейти к строке" ) );
  #if !QT_NO_SHORTCUT
    m_actionGoToRow->setShortcut( tr( "Ctrl+G" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionAbout->setText( tr( "&О программе" ) );
  #if !QT_NO_SHORTCUT
    m_actionAbout->setShortcut( tr( "F1" ) );
  #endif // !QT_NO_SHORTCUT
  m_ActionSaveAllLetterToFile->setText( tr( "Сохранить буквы в файл" ) );
  m_actionDeleteAllBookmarks->setText( tr( "&Удалить все закладки" ) );
  #if !QT_NO_SHORTCUT
    m_actionDeleteAllBookmarks->setShortcut( tr( "Ctrl+Alt+0" ) );
  #endif // !QT_NO_SHORTCUT
  m_actionRegularExpression->setText( tr( "Регулярные выра&жения" ) );
  m_actionAutoPercentBegin->setText( tr( "Авто % в на&чале" ) );
  m_actionAutoPercentEnd->setText( tr( "Авто % в кон&це" ) );
  #if !QT_NO_TOOLTIP
    sbFontSize->setToolTip( tr( "Размер шрифта" ) );
  #endif // !QT_NO_TOOLTIP
  #if !QT_NO_TOOLTIP
    ComboBoxLanguage->setToolTip( tr( "Язык словаря" ) );
  #endif // !QT_NO_TOOLTIP
  #if !QT_NO_TOOLTIP
    ComboBoxLanguageUI->setToolTip( tr( "<html><head/><body><p>Язык программы словаря<br/>Шрилы Прабхупады</p></body></html>" ) );
  #endif // !QT_NO_TOOLTIP
  #if !QT_NO_TOOLTIP
    lineEditRowIndicator->setToolTip( tr( "Текущая строка / всего строк" ) );
  #endif // !QT_NO_TOOLTIP
  #if !QT_NO_WHATSTHIS
    lineEditRowIndicator->setWhatsThis( tr( "<html><head/><body><p>Индикатор, который показывает номер текущей строки, а также общее количество строк в таблице!</p></body></html>" ) );
  #endif // !QT_NO_WHATSTHIS
  #if !QT_NO_TOOLTIP
    ComboBoxSanskrit->setToolTip( tr( "<html><head/><body><p>Поиск по санскриту!</p></body></html>" ) );
  #endif // !QT_NO_TOOLTIP
  #if !QT_NO_WHATSTHIS
    ComboBoxSanskrit->setWhatsThis( tr( "<html><head/><body><p>Поиск по санскриту!</p><p>Можно использовать регулярные выражения!</p></body></html>" ) );
  #endif // !QT_NO_WHATSTHIS
  #if !QT_NO_TOOLTIP
    ComboBoxTranslate->setToolTip( tr( "<html><head/><body><p>Поиск по переводу!</p></body></html>" ) );
  #endif // !QT_NO_TOOLTIP
  #if !QT_NO_WHATSTHIS
    ComboBoxTranslate->setWhatsThis( tr( "<html><head/><body><p>Поиск по переводу!</p><p>Можно использовать регулярные выражения!</p></body></html>" ) );
  #endif // !QT_NO_WHATSTHIS

  menuAction->setTitle( tr( "&Действие" ) );
  menuSet_Bookmark->setTitle( tr( "&Установить закладку" ) );
  menuGo_Bookmarks->setTitle( tr( "&К закладке" ) );

  tbPrabhupada->setWindowTitle( tr( "Прабхупада" ) );

  RetranslateIcon();
} // retranslateUi

QStoragerPrabhupadaDictionaryWindow::QStoragerPrabhupadaDictionaryWindow()
  : inherited()
{
}

QStoragerPrabhupadaDictionaryWindow::~QStoragerPrabhupadaDictionaryWindow()
{
}

void QStoragerPrabhupadaDictionaryWindow::LoadFromStream( void *AObject, QDataStream &ST )
{
  inherited::LoadFromStream( AObject, ST );
  QPrabhupadaDictionaryWindow *O = static_cast< QPrabhupadaDictionaryWindow* >( AObject );
  // 1
  QByteArray AS;
  ST >> AS;
  O->splSanskritTranslate->restoreState( AS );
  // 2
  ST >> AS;
  O->tbvPrabhupadaDictionary->horizontalHeader()->restoreState( AS );
  // 3
  O->m_Storage->LoadFromStream( ST );
  // 4
  LoadFromStreamComboBox( O->ComboBoxSanskrit, ST );
  // 5
  LoadFromStreamComboBox( O->ComboBoxTranslate, ST );
}

void QStoragerPrabhupadaDictionaryWindow::SaveToStream( void *AObject, QDataStream &ST )
{
  inherited::SaveToStream( AObject, ST );
  QPrabhupadaDictionaryWindow *O = static_cast< QPrabhupadaDictionaryWindow* >( AObject );
  // 1
  ST << O->splSanskritTranslate->saveState();
  // 2
  ST << O->tbvPrabhupadaDictionary->horizontalHeader()->saveState();
  // 3
  O->m_Storage->SaveToStream( ST );
  // 4
  SaveToStreamComboBox( O->ComboBoxSanskrit, ST );
  // 5
  SaveToStreamComboBox( O->ComboBoxTranslate, ST );
}
