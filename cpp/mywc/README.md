# mywc

A simplified reimplementation of the Unix `wc` (word count) utility, written from scratch in C++.

Part of [system-programming-lab](../README.md).

## What it is

`mywc` counts the number of lines, words, and bytes in one or more files, or from standard input. It is a learning project focused on stream processing, state machines, and C++ structs.

## Status

**Version 1 — shipped.** Core counting logic, stdin support, multi-file totals, correct exit status. No flags yet.

Planned and deliberately deferred to Version 2: see [Roadmap](#roadmap).

## Features

- Count lines, words, and bytes for one or multiple files
- Read from stdin when no file arguments are given
- Aggregate `total` line when multiple files are processed
- Handles binary files safely (casts bytes to `unsigned char` before checking types)
- Correct exit status: `0` on success, `1` if any file could not be opened or read
- Padded column formatting using `<iomanip>` so output aligns like a table

## What it deliberately does *not* do (Yet)

- Filter output with flags (`-l` for lines, `-w` for words, `-c` for bytes)
- Handle `--help` or `--version`
- Handle the `--` end-of-options marker

## Build

Requires a C++17 compiler and `make`.

```sh
make            # produces ./mywc