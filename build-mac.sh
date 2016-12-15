#!/bin/sh

qmake
make
macdeployqt FishServ/FishServ.app
macdeployqt FishCli/FishCli.app
