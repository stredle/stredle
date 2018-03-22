Larry
================================

Copyright (c) 2009-2014 Bitcoin Developers
Copyright (c) 2011-2014 Stredle Developers
Copyright (c) 2018 RisitasLeGrand

Larry, c'est quoi?
----------------

Larry est une cryptomonnaie, la cryptomonnaie des kheys du 18-25, elle est basée sur Stredle et utilise Scrypt en tant qu'algorithme PoW

 - Un bloc est (normalement) créé toutes les 1 minutes et 30 secondes
 - Division de la block reward tous les 610,000 blocs
 - ~73.2 Millions de LUCK disponibles
 - 60 LUCK par block
 - Taille maximale d'un bloc: 16 Mo
 - Dédi à tous les kheys du 18-25 
 
Licence
-------

Larry est sous licence MIT, plus d'informations ici: http://opensource.org/licenses/MIT

Processus de Développement
-------------------

Les développeurs travaillent dans leurs propres branches, et peuvent ensuite soumettre leurs fonctions quand ils estiment qu'elles sont prêtes

Si il s'agit d'un changement simple / non controversé, la mise à jour sera appliquée (après avoir été soumise à examen)

Si il d'agit d'un changement plus complexe et potentiellement controversé, alors le membre ayant présenté le patch devra démarrer une discution avec les développeurs AINSI que la communauté

Le patch sera accepté si il contient de gros changements OU de petits correctifs
Le code doit OBLIGATOIREMENT respecter les conventions de codage (se référer à doc/coding.txt) auquel cas où le correctif ne sera pas accepté (ou il sera revu si le code présente un changement significatif)

La branche "Master" est souvent compilée et testée mais RIEN ne garantit qu'elle est stable, des [Tags](https://github.com/risitaslegrand/larry/tags) 
sont créés afin d'indiquer des versions officielles et stables de Larry (LUCK)

Je traduirais le reste plus tard :hap:

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./stredle-qt_test

