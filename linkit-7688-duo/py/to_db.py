'''
Push values to database
'''

from __future__ import print_function

import os
import socket
import sys

import requests

sys.path.insert(0, '/usr/lib/python2.7/bridge/')

from bridgeclient import BridgeClient as bridgeclient

BASE_URL = 'http://tz.firc.tw:4000/major/'


def main():
    value = bridgeclient()

    while True:
        t = value.get("t")
        h = value.get("h")

        payload = {
            'char32': socket.gethostname(),
            'float1': float(h),
            'float2': float(t),
            'text': "h, t",
        }
        requests.put(BASE_URL, auth=('demo', 'demo'), json=json)

        print(h, t)


if __name__ == '__main__':
    main()
