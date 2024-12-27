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
#include <QPrabhupadaAboutWindow.h>
#include <QPrabhupada.h>

QPrabhupadaAboutDialog::QPrabhupadaAboutDialog( QWidget *parent, Qt::WindowFlags flags )
  : inherited( parent, flags )
{
    setupUi( this );
}

QPrabhupadaAboutDialog::~QPrabhupadaAboutDialog()
{
}

void QPrabhupadaAboutDialog::changeEvent( QEvent *event )
{
  if ( event->type() == QEvent::LanguageChange ) {
    retranslateUi( this );
  }

  inherited::changeEvent( event );
}

void QPrabhupadaAboutDialog::setupUi( QDialog *APrabhupadaAboutDialog )
{
  if ( APrabhupadaAboutDialog->objectName().isEmpty() ) {
    APrabhupadaAboutDialog->setObjectName( "QPrabhupadaAboutDialog" );
  }
  APrabhupadaAboutDialog->resize(272, 82);
  verticalLayoutPrabhupada = new QVBoxLayout(APrabhupadaAboutDialog);
  verticalLayoutPrabhupada->setObjectName("verticalLayoutPrabhupada");
  verticalLayoutRowNumber = new QVBoxLayout();
  verticalLayoutRowNumber->setObjectName("verticalLayoutRowNumber");
  formLayout = new QFormLayout();
  formLayout->setObjectName("formLayout");
  TabWidgetAbout = new QTabWidget( APrabhupadaAboutDialog );


  verticalLayoutRowNumber->addLayout(formLayout);


  verticalLayoutPrabhupada->addLayout(verticalLayoutRowNumber);

  horizontalLayout = new QHBoxLayout();
  horizontalLayout->setObjectName("horizontalLayout");
  horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  horizontalLayout->addItem(horizontalSpacer);

  PushButtonGo = new QPushButton(APrabhupadaAboutDialog);
  PushButtonGo->setObjectName("PushButtonGo");

  horizontalLayout->addWidget(PushButtonGo);

  PushButtonCancel = new QPushButton(APrabhupadaAboutDialog);
  PushButtonCancel->setObjectName("PushButtonCancel");

  horizontalLayout->addWidget(PushButtonCancel);

  horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

  horizontalLayout->addItem(horizontalSpacer_2);


  verticalLayoutPrabhupada->addLayout(horizontalLayout);

  verticalLayoutPrabhupada->setStretch(0, 1);

  retranslateUi( APrabhupadaAboutDialog );
} // setupUi

void QPrabhupadaAboutDialog::retranslateUi( QDialog *APrabhupadaAboutDialog )
{
  APrabhupadaAboutDialog->setWindowTitle( tr( "О программе" ) );
  PushButtonGo->setText( tr( "Поехали!" ) );
  #if !QT_NO_SHORTCUT
    PushButtonGo->setShortcut( tr( "Return" ) );
  #endif
  PushButtonCancel->setText( tr( "Задний ход!" ) );
  #if !QT_NO_SHORTCUT
    PushButtonCancel->setShortcut( tr( "Esc" ) );
  #endif
} // retranslateUi

QStoragerPrabhupadaAboutDialog::QStoragerPrabhupadaAboutDialog()
  : inherited()
{
}

QStoragerPrabhupadaAboutDialog::~QStoragerPrabhupadaAboutDialog()
{
}

void QStoragerPrabhupadaAboutDialog::LoadFromStream( void *AObject, QDataStream &ST )
{
  inherited::LoadFromStream( AObject, ST );
  // QPrabhupadaAboutDialog *O = static_cast< QPrabhupadaAboutDialog* >( AObject );
  // 1
}

void QStoragerPrabhupadaAboutDialog::SaveToStream( void *AObject, QDataStream &ST )
{
  inherited::SaveToStream( AObject, ST );
  // QPrabhupadaAboutDialog *O = static_cast< QPrabhupadaAboutDialog* >( AObject );
  // 1
}
