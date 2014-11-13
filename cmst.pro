#  Need a make file to make other make files
TEMPLATE = subdirs
SUBDIRS = ./apps/cmstapp ./apps/rootapp

# cmst build variables
include(cmst.pri)

# translations
TRANSLATIONS += ./translations/cmst_ru_RU.ts
