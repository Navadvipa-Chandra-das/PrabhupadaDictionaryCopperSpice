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

#include <PrabhupadaDictionary_build_info.h>
#include <QPrabhupadaLoginWindow.h>
#include <QPrabhupada.h>

QPrabhupadaLoginDialog::QPrabhupadaLoginDialog( QPrabhupadaDictionary *APrabhupadaDictionary
                                              , QWidget *parent
                                              , Qt::WindowFlags flags )
    : inherited( parent, flags )
    , m_PrabhupadaDictionary( APrabhupadaDictionary )
{
    setupUi( this );

    Connects();
    Emits();
}

QPrabhupadaLoginDialog::~QPrabhupadaLoginDialog()
{
}

void QPrabhupadaLoginDialog::Connects()
{
  QObject::connect( radioButtonSQLite
                  , &QAbstractButton::toggled
                  , this
                  , &QPrabhupadaLoginDialog::SQLRadioButton );
  radioButtonSQLite->setChecked( true );

  QObject::connect( ComboBoxLanguageUI
                  , cs_mp_cast< int >( &QComboBox::currentIndexChanged )
                  , &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SetValue );
  QObject::connect( &m_PrabhupadaDictionary->m_LanguageUIIndex
                  , &QLanguageIndex::SignalValueChanged
                  , this
                  , &QPrabhupadaLoginDialog::LanguageUI_IndexChanged );
  QObject::connect( pushButtonOK
                  , &QPushButton::clicked
                  , this
                  , &QPrabhupadaLoginDialog::pushButtonOKClicked );
  QObject::connect( pushButtonCancel
                  , &QPushButton::clicked
                  , this
                  , &QPrabhupadaLoginDialog::pushButtonCancelClicked );
}

void QPrabhupadaLoginDialog::Emits()
{
  m_PrabhupadaDictionary->m_LanguageUIIndex.EmitValueChanged();
}

void QPrabhupadaLoginDialog::pushButtonOKClicked()
{
  accept();
}

void QPrabhupadaLoginDialog::pushButtonCancelClicked()
{
  reject();
}

void QPrabhupadaLoginDialog::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void QPrabhupadaLoginDialog::DatabaseToWidget( QSqlDatabase *DB )
{
  ComboBoxUserName    ->setEditText( DB->userName() );
  ComboBoxDatabaseName->setEditText( DB->databaseName() );
  ComboBoxHostName    ->setEditText( DB->hostName() );
  ComboBoxPort        ->setEditText( QString::number( DB->port() ) );
}

void QPrabhupadaLoginDialog::WidgetToDatabase( QSqlDatabase *DB )
{
  DB->setUserName( ComboBoxUserName->currentText () );
  if ( radioButtonSQLite->isChecked() ) {
    DB->setDatabaseName( QPrabhupadaDictionary::PrabhupadaDictionaryFiles + "Sanskrit.db" );
  } else {
    DB->setDatabaseName( ComboBoxDatabaseName->currentText() );
  }
  DB->setHostName( ComboBoxHostName->currentText() );
  DB->setPort( ComboBoxPort->currentText().toInt() );
  DB->setPassword( LineEditPassword->text() );
}

void QPrabhupadaLoginDialog::SQLRadioButton( bool checked )
{
  LabelUserName       ->setEnabled( !checked );
  LabelPassword       ->setEnabled( !checked );
  LabelDatabaseName   ->setEnabled( !checked );
  LabelHostName       ->setEnabled( !checked );
  LabelPort           ->setEnabled( !checked );
  LabelSchema         ->setEnabled( !checked );

  ComboBoxUserName    ->setEnabled( !checked );
  LineEditPassword    ->setEnabled( !checked );
  ComboBoxDatabaseName->setEnabled( !checked );
  ComboBoxHostName    ->setEnabled( !checked );
  ComboBoxPort        ->setEnabled( !checked );
  ComboBoxSchema      ->setEnabled( !checked );

  if ( checked ) {
    m_DriverName = "QSQLITE";
    m_Schema = "";
  } else {
    m_DriverName = "QPSQL";
    m_Schema = ComboBoxSchema->currentText() + ".";
  }
}

bool QPrabhupadaLoginDialog::Connect( QSqlDatabase *DB )
{
  WidgetToDatabase( DB );
  bool B = DB->open();
  if ( B ) {
    PrepareHistoryComboBox( ComboBoxUserName );
    PrepareHistoryComboBox( ComboBoxDatabaseName );
    PrepareHistoryComboBox( ComboBoxHostName );
    PrepareHistoryComboBox( ComboBoxPort );
    PrepareHistoryComboBox( ComboBoxSchema );
  }
  return B;
}

void QPrabhupadaLoginDialog::LanguageUI_IndexChanged( int Value )
{
  ComboBoxLanguageUI->setCurrentIndex( Value );
}

void QPrabhupadaLoginDialog::setupUi(QDialog *APrabhupadaLoginDialog)
{
  if ( APrabhupadaLoginDialog->objectName().isEmpty() ) {
    APrabhupadaLoginDialog->setObjectName( "QPrabhupadaLoginDialog" );
  }
  APrabhupadaLoginDialog->setWindowModality( Qt::NonModal );
  APrabhupadaLoginDialog->resize(265, 296);
  APrabhupadaLoginDialog->setMouseTracking(false);
  QIcon icon;
  icon.addFile(QString::fromUtf8(":/Icon/resources/PrabhupadaDictionary.ico"), QSize(), QIcon::Normal, QIcon::Off);
  APrabhupadaLoginDialog->setWindowIcon(icon);
  APrabhupadaLoginDialog->setModal(false);
  LayoutPrabhupadaLogin = new QVBoxLayout(APrabhupadaLoginDialog);
  LayoutPrabhupadaLogin->setObjectName("LayoutPrabhupadaLogin");
  LayoutSQL = new QHBoxLayout();
  LayoutSQL->setObjectName("LayoutSQL");
  radioButtonSQLite = new QRadioButton(APrabhupadaLoginDialog);
  radioButtonSQLite->setObjectName("radioButtonSQLite");

  LayoutSQL->addWidget(radioButtonSQLite);

  radioButtonPostgreSQL = new QRadioButton(APrabhupadaLoginDialog);
  radioButtonPostgreSQL->setObjectName("radioButtonPostgreSQL");

  LayoutSQL->addWidget(radioButtonPostgreSQL);


  LayoutPrabhupadaLogin->addLayout(LayoutSQL);

  LayoutConnection = new QFormLayout();
  LayoutConnection->setObjectName("LayoutConnection");
  LabelUserName = new QLabel(APrabhupadaLoginDialog);
  LabelUserName->setObjectName("LabelUserName");

  LayoutConnection->setWidget(0, QFormLayout::LabelRole, LabelUserName);

  ComboBoxUserName = new QComboBox(APrabhupadaLoginDialog);
  ComboBoxUserName->setObjectName("ComboBoxUserName");
  ComboBoxUserName->setEditable(true);

  LayoutConnection->setWidget(0, QFormLayout::FieldRole, ComboBoxUserName);

  LabelPassword = new QLabel(APrabhupadaLoginDialog);
  LabelPassword->setObjectName("LabelPassword");

  LayoutConnection->setWidget(1, QFormLayout::LabelRole, LabelPassword);

  LineEditPassword = new QLineEdit(APrabhupadaLoginDialog);
  LineEditPassword->setObjectName("LineEditPassword");
  LineEditPassword->setEchoMode(QLineEdit::Password);
  LineEditPassword->setClearButtonEnabled(false);

  LayoutConnection->setWidget(1, QFormLayout::FieldRole, LineEditPassword);

  LabelDatabaseName = new QLabel(APrabhupadaLoginDialog);
  LabelDatabaseName->setObjectName("LabelDatabaseName");

  LayoutConnection->setWidget(2, QFormLayout::LabelRole, LabelDatabaseName);

  ComboBoxDatabaseName = new QComboBox(APrabhupadaLoginDialog);
  ComboBoxDatabaseName->setObjectName("ComboBoxDatabaseName");
  ComboBoxDatabaseName->setEditable(true);

  LayoutConnection->setWidget(2, QFormLayout::FieldRole, ComboBoxDatabaseName);

  LabelHostName = new QLabel(APrabhupadaLoginDialog);
  LabelHostName->setObjectName("LabelHostName");

  LayoutConnection->setWidget(3, QFormLayout::LabelRole, LabelHostName);

  ComboBoxHostName = new QComboBox(APrabhupadaLoginDialog);
  ComboBoxHostName->setObjectName("ComboBoxHostName");
  ComboBoxHostName->setEditable(true);

  LayoutConnection->setWidget(3, QFormLayout::FieldRole, ComboBoxHostName);

  LabelPort = new QLabel(APrabhupadaLoginDialog);
  LabelPort->setObjectName("LabelPort");

  LayoutConnection->setWidget(4, QFormLayout::LabelRole, LabelPort);

  ComboBoxPort = new QComboBox(APrabhupadaLoginDialog);
  ComboBoxPort->setObjectName("ComboBoxPort");
  ComboBoxPort->setEditable(true);

  LayoutConnection->setWidget(4, QFormLayout::FieldRole, ComboBoxPort);

  LabelSchema = new QLabel(APrabhupadaLoginDialog);
  LabelSchema->setObjectName("LabelSchema");

  LayoutConnection->setWidget(5, QFormLayout::LabelRole, LabelSchema);

  ComboBoxSchema = new QComboBox(APrabhupadaLoginDialog);
  ComboBoxSchema->setObjectName("ComboBoxSchema");
  ComboBoxSchema->setEditable(true);

  LayoutConnection->setWidget(5, QFormLayout::FieldRole, ComboBoxSchema);

  CheckBoxResetSettings = new QCheckBox(APrabhupadaLoginDialog);
  CheckBoxResetSettings->setObjectName("CheckBoxResetSettings");

  LayoutConnection->setWidget(6, QFormLayout::FieldRole, CheckBoxResetSettings);

  LabelLanguageUI = new QLabel(APrabhupadaLoginDialog);
  LabelLanguageUI->setObjectName("LabelLanguageUI");

  LayoutConnection->setWidget(7, QFormLayout::LabelRole, LabelLanguageUI);

  ComboBoxLanguageUI = new QComboBox(APrabhupadaLoginDialog);
  ComboBoxLanguageUI->setObjectName("ComboBoxLanguageUI");

  LayoutConnection->setWidget(7, QFormLayout::FieldRole, ComboBoxLanguageUI);


  LayoutPrabhupadaLogin->addLayout(LayoutConnection);

  horizontalLayout = new QHBoxLayout();
  horizontalLayout->setObjectName("horizontalLayout");
  horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  horizontalLayout->addItem(horizontalSpacer);

  pushButtonOK = new QPushButton(APrabhupadaLoginDialog);
  pushButtonOK->setObjectName("pushButtonOK");

  horizontalLayout->addWidget(pushButtonOK);

  pushButtonCancel = new QPushButton(APrabhupadaLoginDialog);
  pushButtonCancel->setObjectName("pushButtonCancel");
  pushButtonCancel->setAutoDefault(true);

  horizontalLayout->addWidget(pushButtonCancel);

  horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  horizontalLayout->addItem(horizontalSpacer_2);


  LayoutPrabhupadaLogin->addLayout(horizontalLayout);

  QWidget::setTabOrder(radioButtonSQLite, radioButtonPostgreSQL);
  QWidget::setTabOrder(radioButtonPostgreSQL, ComboBoxUserName);
  QWidget::setTabOrder(ComboBoxUserName, LineEditPassword);
  QWidget::setTabOrder(LineEditPassword, ComboBoxDatabaseName);
  QWidget::setTabOrder(ComboBoxDatabaseName, ComboBoxHostName);
  QWidget::setTabOrder(ComboBoxHostName, ComboBoxPort);
  QWidget::setTabOrder(ComboBoxPort, ComboBoxSchema);
  QWidget::setTabOrder(ComboBoxSchema, CheckBoxResetSettings);

  radioButtonSQLite->setText( "SQLite" );
  radioButtonPostgreSQL->setText( "PostgreSQL" );

  retranslateUi(APrabhupadaLoginDialog);

  pushButtonOK->setDefault(true);


  QMetaObject::connectSlotsByName(APrabhupadaLoginDialog);
} // setupUi

void QPrabhupadaLoginDialog::retranslateUi( QDialog *APrabhupadaLoginDialog )
{
  APrabhupadaLoginDialog->setWindowTitle( tr( "Вход в \"Словарь Шрилы Прабхупады\"" ) );
  LabelUserName->    setText( tr( "Имя пользователя" ) );
  LabelPassword->    setText( tr( "Пароль" ) );
  LabelDatabaseName->setText( tr( "Имя базы данных" ) );
  LabelHostName->    setText( tr( "Сервер" ) );
  LabelPort->        setText( tr( "Порт" ) );
  LabelSchema->      setText( tr( "Схема" ) );

  #if QT_NO_WHATSTHIS
    CheckBoxResetSettings->setWhatsThis( tr( "<html><head/><body><p>Этот флаг сбрасывает все настройки пользователя после входа в программу! Но только те из них, которые хранятся в базе данных! Настройки, хранящиеся в файлах &quot;ini&quot; сбрасывайте простым удалением этих файлов!</p></body></html>" ) );
  #endif

  CheckBoxResetSettings->setText( tr( "Сбросить настройки" ) );
  LabelLanguageUI->      setText( tr( "Язык программы" ) );
  pushButtonOK->         setText( tr( "Поехали!" ) );
  pushButtonCancel->     setText( tr( "Задний ход!" ) );
} // retranslateUi

QStoragerPrabhupadaLoginDialog::QStoragerPrabhupadaLoginDialog()
  : inherited()
{
}

QStoragerPrabhupadaLoginDialog::~QStoragerPrabhupadaLoginDialog()
{
}

void QStoragerPrabhupadaLoginDialog::LoadFromStream( void *AObject, QDataStream &ST )
{
  inherited::LoadFromStream( AObject, ST );
  QPrabhupadaLoginDialog *O = static_cast< QPrabhupadaLoginDialog* >( AObject );
  // 1
  LoadFromStreamComboBox( O->ComboBoxUserName, ST );
  // 2
  LoadFromStreamComboBox( O->ComboBoxDatabaseName, ST );
  // 3
  LoadFromStreamComboBox( O->ComboBoxHostName, ST );
  // 4
  LoadFromStreamComboBox( O->ComboBoxPort, ST );
  // 5
  LoadFromStreamComboBox( O->ComboBoxSchema, ST );
  // 6
  bool B;
  ST >> B;
  if ( B ) {
    O->radioButtonSQLite->setChecked( true );
  } else {
    O->radioButtonPostgreSQL->setChecked( true );
  }
}

void QStoragerPrabhupadaLoginDialog::SaveToStream( void *AObject, QDataStream &ST )
{
  inherited::SaveToStream( AObject, ST );
  QPrabhupadaLoginDialog *O = static_cast< QPrabhupadaLoginDialog* >( AObject );
  // 1
  SaveToStreamComboBox( O->ComboBoxUserName, ST );
  // 2
  SaveToStreamComboBox( O->ComboBoxDatabaseName, ST );
  // 3
  SaveToStreamComboBox( O->ComboBoxHostName, ST );
  // 4
  SaveToStreamComboBox( O->ComboBoxPort, ST );
  // 5
  SaveToStreamComboBox( O->ComboBoxSchema, ST );
  // 6
  ST << O->radioButtonSQLite->isChecked();
}
