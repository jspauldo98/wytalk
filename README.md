# wytalk

wytalk is a utility program that mimics the Linux talk utility. It is designed to talk to another user over the same port. This is a project for Linux Programming (COSC 3750).

## Prerequisites

GNU make is required.

## Installation

Use the GNU make utility to compile.

```bash
make
```

## Synopsis

```bash
./wytalkD # Start the server process
./wytalkC [HOST] # Client connects to server host
```

## Description

HOST is the name of the machine the server is running on. Server and client connect over port 51100

## Author

Jared Spaulding, Kim Buckner
