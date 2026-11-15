# mycat

A simplified reimplementation of the Unix `cat` utility, written from scratch in C++.

Part of [system-programming-lab](../README.md).

## What it is

`mycat` copies bytes from standard input or from named files to standard output,
exactly as real `cat` does. It is a **byte pump** — it has no concept of lines,
encoding, or text. Whatever bytes go in come out, unmodified, in order.

This is a learning project. The point is not to reimplement `cat` (which already
exists and is better) — it is to practice file I/O, command-line argument handling,
streams, error handling, and program decomposition against a real, small, honest
problem.

## Status

**Version 1 — shipped.** Core byte pump, stdin support, per-file error handling,
correct exit status. No flags yet.

Planned and deliberately deferred to Version 2: see [Roadmap](#roadmap).

## Features

- Copy one or more files to stdout, in argument order
- Read from stdin when no file arguments are given
- Binary-safe: copies bytes exactly, including NUL bytes and files with no trailing newline(copies bytes verbatim)
- Per-file error reporting to stderr; continues to subsequent files on failure
- Correct exit status: `0` iff every input was read successfully, `1` otherwise
- Fixed 64 KiB buffer — no per-byte syscalls, no unbounded allocation

## What it deliberately does *not* do

- Number, highlight, or annotate lines (that's `-n`, `-b`, `-A` — Version 2)
- Print filename headers between files (that's `head -v` / `grep -H`'s job)
- Transform, filter, or parse its input in any way

`mycat`'s output is byte-identical to the concatenation of its inputs. Any tool
that wants to label, number, or filter can do so *downstream* of `mycat` — that's
what pipes are for.

## Build

Requires a C++17 compiler and `make`.

```sh
make            # produces ./mycat