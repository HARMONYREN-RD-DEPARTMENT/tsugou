#!/bin/bash
set -e

npm run build
node dist/main.js "$@"
