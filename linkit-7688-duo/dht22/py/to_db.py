from __future__ import print_function

import os
import socket
import sys

from time import time

import requests

sys.path.insert(0, '/usr/lib/python2.7/bridge/')

from bridgeclient import BridgeClient as bridgeclient

ID = 1
API_URL = 'http://lbp.firc.tw:3000/iot/{id}/'.format(ID)


def main():
    value = bridgeclient()

    while True:
        t = value.get('t')
        h = value.get('h')

        payload = {
            'hostname': socket.gethostname(),
            'humi': float(h),
            'temp': float(t),
        }
        r = requests.post(API_URL, json=payload)
        assert r.status_code == 201, r.status_code

        print(h, t)


if __name__ == '__main__':
    main()
