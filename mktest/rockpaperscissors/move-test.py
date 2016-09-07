#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import shutil

stt = 1

for stt in range(1, 11):
	shutil.move(''.join(['in', str(stt), '.INP']), ''.join(['test', str(stt), '/', 'rockpaperscissors.INP']))
	shutil.move(''.join(['in', str(stt), '.out']), ''.join(['test', str(stt), '/', 'rockpaperscissors.OUT']))
