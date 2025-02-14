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
#include <QPrabhupadaGoToLineWindow.h>
#include <QPrabhupada.h>

QPrabhupadaGoToLineDialog::QPrabhupadaGoToLineDialog( QWidget *parent, Qt::WindowFlags flags )
  : inherited( parent, flags )
{
  setupUi( this );
  QObject::connect( PushButtonGo
                  , &QPushButton::clicked
                  , this
                   , &QPrabhupadaGoToLineDialog::PushButtonGoClicked );
  QObject::connect( PushButtonCancel
                  , &QPushButton::clicked
                  , this
                   , &QPrabhupadaGoToLineDialog::PushButtonCancelClicked );
}

QPrabhupadaGoToLineDialog::~QPrabhupadaGoToLineDialog()
{
}

void QPrabhupadaGoToLineDialog::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void QPrabhupadaGoToLineDialog::PushButtonGoClicked()
{
  accept();
  emit SignalGoToLine( ComboBoxRowNumber->currentText().toInt() );
}

void QPrabhupadaGoToLineDialog::PushButtonCancelClicked()
{
  reject();
}

void QPrabhupadaGoToLineDialog::setupUi( QDialog *APrabhupadaGoToLineDialog )
{
    if ( APrabhupadaGoToLineDialog->objectName().isEmpty() ) {
      APrabhupadaGoToLineDialog->setObjectName( "QPrabhupadaGoToLineDialog" );
    }
    APrabhupadaGoToLineDialog->resize(272, 82);
    verticalLayoutPrabhupada = new QVBoxLayout(APrabhupadaGoToLineDialog);
    verticalLayoutPrabhupada->setObjectName("verticalLayoutPrabhupada");
    verticalLayoutRowNumber = new QVBoxLayout();
    verticalLayoutRowNumber->setObjectName("verticalLayoutRowNumber");
    formLayout = new QFormLayout();
    formLayout->setObjectName("formLayout");
    LabelRowNumber = new QLabel(APrabhupadaGoToLineDialog);
    LabelRowNumber->setObjectName("LabelRowNumber");

    formLayout->setWidget(0, QFormLayout::LabelRole, LabelRowNumber);

    ComboBoxRowNumber = new QComboBox(APrabhupadaGoToLineDialog);
    ComboBoxRowNumber->setObjectName("ComboBoxRowNumber");
    ComboBoxRowNumber->setProperty("editable", QVariant(true));

    formLayout->setWidget(0, QFormLayout::FieldRole, ComboBoxRowNumber);


    verticalLayoutRowNumber->addLayout(formLayout);


    verticalLayoutPrabhupada->addLayout(verticalLayoutRowNumber);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName("horizontalLayout");
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    PushButtonGo = new QPushButton(APrabhupadaGoToLineDialog);
    PushButtonGo->setObjectName("PushButtonGo");

    horizontalLayout->addWidget(PushButtonGo);

    PushButtonCancel = new QPushButton(APrabhupadaGoToLineDialog);
    PushButtonCancel->setObjectName("PushButtonCancel");

    horizontalLayout->addWidget(PushButtonCancel);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_2);


    verticalLayoutPrabhupada->addLayout(horizontalLayout);

    verticalLayoutPrabhupada->setStretch(0, 1);

    retranslateUi( APrabhupadaGoToLineDialog );
} // setupUi

void QPrabhupadaGoToLineDialog::retranslateUi( QDialog *APrabhupadaGoToLineDialog )
{
  APrabhupadaGoToLineDialog->setWindowTitle( tr( "Перейти к строке" ) );
  LabelRowNumber->setText( tr( "Номер строки" ) );
  #if !QT_NO_WHATSTHIS
    ComboBoxRowNumber->setWhatsThis( tr( "<html><head/><body><p>Введите номер строки и нажмите Enter для перехода к ней!</p></body></html>" ) );
  #endif
  #if !QT_NO_TOOLTIP
    ComboBoxRowNumber->setToolTip( tr( "Номер строки" ) );
  #endif
  PushButtonGo->setText( tr( "Поехали!" ) );
  #if !QT_NO_SHORTCUT
    PushButtonGo->setShortcut( tr( "Return" ) );
  #endif
  PushButtonCancel->setText( tr( "Задний ход!" ) );
  #if !QT_NO_SHORTCUT
    PushButtonCancel->setShortcut( tr( "Esc" ) );
  #endif
} // retranslateUi

QStoragerPrabhupadaGoToLineDialog::QStoragerPrabhupadaGoToLineDialog()
  : inherited()
{
}

QStoragerPrabhupadaGoToLineDialog::~QStoragerPrabhupadaGoToLineDialog()
{
}

void QStoragerPrabhupadaGoToLineDialog::LoadFromStream( void *AObject, QDataStream &ST )
{
  inherited::LoadFromStream( AObject, ST );
  QPrabhupadaGoToLineDialog *O = static_cast< QPrabhupadaGoToLineDialog* >( AObject );
  // 1
  LoadFromStreamComboBox( O->ComboBoxRowNumber, ST );
}

void QStoragerPrabhupadaGoToLineDialog::SaveToStream( void *AObject, QDataStream &ST )
{
  inherited::SaveToStream( AObject, ST );
  QPrabhupadaGoToLineDialog *O = static_cast< QPrabhupadaGoToLineDialog* >( AObject );
  // 1
  SaveToStreamComboBox( O->ComboBoxRowNumber, ST );
}
