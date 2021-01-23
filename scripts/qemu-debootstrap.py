#!/usr/bin/env python3

# allows treating some lines in editor as if they were from a file)
from io import StringIO
import sys
import bs4
import requests

url = 'https://salsa.debian.org/qemu-team/qemu/-/blob/master/debian/qemu-debootstrap'
soup = bs4.BeautifulSoup(requests.get(url).text, "html.parser")
commit_hash = str(
    soup.find_all("div", class_="label label-monospace monospace")[0].string
).replace("\n", "")

datetime = str(soup.find_all("time", class_="js-timeago")[0]['datetime'])

date = datetime[:10].replace('-', '')
time = datetime[-9:-1].replace(":", '')
print(date+"."+time+"." + commit_hash)
