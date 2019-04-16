Stredle integration/staging tree
================================

WARNING: This source code (Stredle V2) is **NOT** working, here's the last working Stredle source code: https://github.com/stredle/stredle/tree/v0.8.7.5

----------------
https://stredle.github.io/

Copyright (c) 2009-2014 Bitcoin Developers
Copyright (c) 2011-2018 Litecoin Developers
Copyright (c) 2019 Stredle Developers

What is Stredle?
----------------

Stredle is a fork of Litecoin using scrypt as a proof-of-work algorithm.
 - 60 sec block targets
 - subsidy halves in 580k blocks
 - ~75.4 million total coins
 - 15MB Max block size
 
 *Port Forwarding*
 TCP: 1253
 JSON RPC: 1254
 
 Testnet TCP: 25366
 Testnet JSON RPC: 25361

The rest is the same as Litecoin.


For more information, as well as an immediately useable, binary version of
the Stredle client sofware, see https://stredle.github.io/

License
-------

Stredle is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Stredle
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion with the devs and community.

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/Stredle-project/Stredle/tags) are created
regularly to indicate new official, stable release versions of Stredle.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.
