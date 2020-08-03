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
TRANSLATIONS += ./translations/cmst_fr_FR.ts
TRANSLATIONS += ./translations/cmst_tr_TR.ts
TRANSLATIONS += ./translations/cmst_nl_NL.ts

# non-application files which need to be installed
#
# documentation (manpage)
documentation.path = $$CMST_DOC_PATH/man1
documentation.files = ./misc/manpage/cmst.1.gz
documentation.CONFIG = no_check_exist
documentation.extra = gzip --force --keep ./misc/manpage/cmst.1
INSTALLS += documentation

# application icons - 
exists(./images/application/cmst-icon.png) {
	LIST = 16 20 22 24 32 36 40 48 64 72 96 128 192 256 384 512
	for(a, LIST) {
		icon$${a}.path = /usr/share/icons/hicolor/$${a}x$${a}/apps
		icon$${a}.files = ./images/application/$${a}x$${a}/cmst.png
		INSTALLS += icon$${a}
	}
	exists(./images/application/scalable/cmst.svg) {
		iconsvg.path = /usr/share/icons/hicolor/scalable/apps
		iconsvg.files = ./images/application/scalable/cmst.svg
		INSTALLS += iconsvg
	}
} else {
	system(sed -i 's/Icon=cmst/Icon=preferences-system-network/g' "./misc/desktop/cmst.desktop")
	system(sed -i 's/Icon=cmst/Icon=preferences-system-network/g' "./misc/desktop/cmst-autostart.desktop")
}

# license
license.path = /usr/share/licenses/cmst
license.files = ./text/LICENSE
INSTALLS += license

# appdata
appdata.path = /usr/share/metainfo
appdata.files = ./misc/appdata/org.cmst.cmst.appdata.xml
INSTALLS += appdata

# desktop file
desktop.path = /usr/share/applications
desktop.files = ./misc/desktop/cmst.desktop
!isEmpty(DESTDIR) {
	desktop.extra = gtk-update-icon-cache /usr/share/icons/hicolor
}
INSTALLS += desktop
 
# autostart desktop file
autostart.path = /usr/share/cmst/autostart
autostart.files = ./misc/desktop/cmst-autostart.desktop
INSTALLS += autostart
