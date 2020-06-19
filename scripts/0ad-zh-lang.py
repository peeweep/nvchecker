#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2020 peeweep <peeweep@0x0.ee>
#
# Distributed under terms of the MIT license.

import requests
req = requests.get("http://releases.wildfiregames.com/locales/").text
split_req = req.split('<a href="zh-lang-')
last_split_req = split_req[len(split_req)-1]
version = last_split_req.split('.pyromod">http</a></td></tr>')[0]
print(version)
