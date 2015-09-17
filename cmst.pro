#  Need a make file to make other make files
TEMPLATE = subdirs
SUBDIRS = ./apps/cmstapp ./apps/rootapp

# cmst build variables
include(cmst.pri)

# translations
TRANSLATIONS += ./translations/cmst_en_US.ts
TRANSLATIONS += ./translations/cmst_ru_RU.ts
TRANSLATIONS += ./translations/cmst_zh_CN.ts
TRANSLATIONS += ./translations/cmst_de_DE.ts
TRANSLATIONS += ./translations/cmst_pl_PL.ts
TRANSLATIONS += ./translations/cmst_it_IT.ts
TRANSLATIONS += ./translations/cmst_es_ES.ts
TRANSLATIONS += ./translations/cmst_es_CO.ts

# if we can't find the cmst.png icon then substitue an fdo icon inside the desktop files.
!exists( ./images/application/cmst.png ) {
system(sed -i 's/Icon=cmst/Icon=preferences-system-network/g' "./misc/desktop/cmst.desktop")
system(sed -i 's/Icon=cmst/Icon=preferences-system-network/g' "./misc/desktop/cmst-autostart.desktop")
}

