TEMPLATE = aux

# translations
TRANSLATIONS += ./cmst_bg_BG.ts
TRANSLATIONS += ./cmst_cs.ts
TRANSLATIONS += ./cmst_de_DE.ts
TRANSLATIONS += ./cmst_en_US.ts
TRANSLATIONS += ./cmst_es_CO.ts
TRANSLATIONS += ./cmst_es_ES.ts
TRANSLATIONS += ./cmst_fr_FR.ts
TRANSLATIONS += ./cmst_hu_HU.ts
TRANSLATIONS += ./cmst_it_IT.ts
TRANSLATIONS += ./cmst_lt.ts
TRANSLATIONS += ./cmst_nb_NO.ts
TRANSLATIONS += ./cmst_nl_NL.ts
TRANSLATIONS += ./cmst_pl_PL.ts
TRANSLATIONS += ./cmst_pt_BR.ts
TRANSLATIONS += ./cmst_pt.ts
TRANSLATIONS += ./cmst_ru_RU.ts
TRANSLATIONS += ./cmst_si.ts
TRANSLATIONS += ./cmst_tr_TR.ts
TRANSLATIONS += ./cmst_uk.ts
TRANSLATIONS += ./cmst_zh_CN.ts

# create required build directories
mkpath(./.qm)
CONFIG += lrelease
