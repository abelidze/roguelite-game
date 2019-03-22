About RogueliteGame
==============

RogueliteGame is console dungeon crawler game.
It's not finished yet and maybe won't be finished in future.

Written in Native-С++ using PDCurses library.

Installation
------------

Download project as '.zip' archive and extract it to whatever you like directory or use `git`:
```sh
$ git clone https://github.com/abelidze/roguelite-game.git
```

Requirements
------------

* PDCurses (tested and working with v3.4)
* Currently not compatible with ncurses stuff

Running
-------

> **TESTS**

```sh
make test && make clean && ./bin/game
```

> **COVERAGE**

```sh
make cov && make clean && ./bin/game
```

> **BUILD & RUN**

```sh
make && ./bin/game
```

* Tested with MinGW x64 and its `make` utility, but you can use any working C / C++ compiler.

Contact
-------

Developers on Telegram:

[![https://t.me/Abelidze](https://img.shields.io/badge/%E2%9E%A4Telegram-@Abelidze-DD2200.svg?style=flat-square&&colorA=2D233B)](https://t.me/Abelidze)

License
-------
RogueliteGame is open-sourced software licensed under the [MIT License](http://opensource.org/licenses/MIT).

#### Disclaimer

This program is provided "AS IS" without warranty of any kind.