__Senesnės versijos:__

Objektinio programavimo duomenų mokslui pirmo namų darbo užduoties versija 1.2

**Atsisiuntę rasite:**
main.cpp - programos kodas skirtas realizuoti užduočiai
Klase.h - duomenų klasę ir jos funkcijas turinti antraštė
klase.cpp - duomenų klasės funkcijų aprašas
generavimas.h - failų generavimui skirta antraštė
struktura.h - duomenų struktūrą ir jos funkcijas turinti antraštė
struktura.cpp - struktūros duomenų funkcijos
Fun.h - programos funkcijų antraštė
Fun.cpp - programos funcijos

**Kas naujo:**
Klase.h antraštėje pridėtas destruktorius, operatoriai

Objektinio programavimo duomenų mokslui pirmo namų darbo užduoties versija 1.1

**Atsisiuntę rasite:**
main.cpp - programos kodas skirtas realizuoti užduočiai
Klase.h - duomenų klasę ir jos funkcijas turinti antraštė
klase.cpp - duomenų klasės funkcijų aprašas
generavimas.h - failų generavimui skirta antraštė
struktura.h - duomenų struktūrą ir jos funkcijas turinti antraštė
struktura.cpp - struktūros duomenų funkcijos
Fun.h - programos funkcijų antraštė
Fun.cpp - programos funcijos

**Kas naujo:**
Šiek tiek pakeistas programos kodas, programos funkcijos išskaidytos į daugiau failų, kad būtų lengviau naviguojamos.
Struktūra duomenys pakeista į klasę.

**Programos darbo laiko analizė lyginant STRUCT ir CLASS:**
![Klases ir strukturos lyginimas](https://user-images.githubusercontent.com/71488215/101383695-2164d800-38c2-11eb-860e-dd2829943216.JPG)
Kaip matome, naudojant __class__ vietoj __stuct__ turime ilgesnį nuskaitymo laiką, tačiau daugmaž dvigubai greičiau failai yra išskaidomi į naujus vargšelių ir galvočių konteinerius.

__Programos darbas keičiant flag'us:__
Tarp O1 ir O2 optimizavimo flag'ų pagrindinis skirtumas toks, kad naudojant O2 flag'ą failai buvo greičiau nuskaitomi, skirstymas į naujus konteinerius labai panašus,
Ox flag'as failus nuskaitė labai panašiai kaip ir O2, tačiau šiek tiek greičiau juos išskaidė į 2 naujus konteinerius.
Paveikslėliai žemiau:
O1:
![1 1 Programa O1](https://user-images.githubusercontent.com/71488215/101384589-502f7e00-38c3-11eb-8e0e-473033bb1901.JPG)
O2:
![1 1 Programa O2](https://user-images.githubusercontent.com/71488215/101384605-53c30500-38c3-11eb-812b-64e31a10c3da.JPG)
Ox:
![1 1 Programa Ox](https://user-images.githubusercontent.com/71488215/101384741-83720d00-38c3-11eb-928e-7f4421aec65d.JPG)
