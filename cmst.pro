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

# non-application files which need to be installed
#
# documentation (manpage)
documentation.path = $$CMST_DOC_PATH/man1
documentation.files = ./misc/manpage/cmst.1.gz
documentation.CONFIG = no_check_exist
documentation.extra = gzip --force --keep ./misc/manpage/cmst.1
INSTALLS += documentation

# application icons - scalable icon (used internally) won't be used
# unless the 24x24 (used for desktop files) exists.
exists(./images/application/cmst.png) 
	icon24.path = /usr/share/icons/hicolor/24x24/apps
	icon24.files = ./images/application/cmst.png
	INSTALLS += icon24
	exists(./images/application/cmst.svg) {
		iconsvg.path = /usr/share/icons/hicolor/scalable/apps
		iconsvg.files = ./images/application/cmst.svg
		INSTALLS += iconsvg
}
else {
	system(sed -i 's/Icon=cmst/Icon=preferences-system-network/g' "./misc/desktop/cmst.desktop")
	system(sed -i 's/Icon=cmst/Icon=preferences-system-network/g' "./misc/desktop/cmst-autostart.desktop")
}

# desktop file
desktop.path = /usr/share/applications
desktop.files = ./misc/desktop/cmst.desktop
INSTALLS += desktop

# autostart desktop file
autostart.path = /usr/share/cmst/autostart
autostart.files = ./misc/desktop/cmst-autostart.desktop
INSTALLS += autostart
