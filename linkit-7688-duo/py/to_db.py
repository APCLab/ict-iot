from __future__ import print_function

import os
import socket
import sys

from time import time

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
            'int1': int(time()),  # timestamp
            'float1': float(h),
            'float2': float(t),
            'text': "h, t",
        }
        r = requests.post(BASE_URL, auth=('demo', 'demo'), json=payload)
        assert r.status_code == 201, r.status_code

        print(h, t)


if __name__ == '__main__':
    main()
