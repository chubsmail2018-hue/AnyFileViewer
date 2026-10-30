# AnyFileViewer

A safe file opener and runner that can open files even when they have no associated app, detect unknown formats, and execute custom script files such as TMP language files.

## Features

- Detects file types by content and extension
- Opens unknown files in raw text or hex preview mode
- Runs custom script files with a safe interpreter
- Blocks native executables by default
- Suitable for custom formats like `.tmp`, `.dat`, `.bin`, and `.unk`

## Example custom TMP script

```text
TMP1.12B
SET HP 100
SET AMMO 30
PRINT "HUNTER3D"
LOOP 3
  PRINT "Zombie Hunt!"
END
```

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/anyfileviewer example.tmp
```

## Safety rule

This project is intentionally safe by default:

- Unknown native executables are not run automatically
- Only recognized script headers are executed
- Unknown files are opened in preview mode instead of being executed
