#!/bin/zsh

set -euo pipefail

print_section() {
  echo
  echo "==== $1 ===="
}

check_cmd() {
  local display_name="$1"
  local base_cmd="$2"
  local bin_name
  bin_name=${base_cmd%% *}

  print_section "$display_name"
  if command -v "$bin_name" >/dev/null 2>&1; then
    eval "$base_cmd"
    which "$bin_name" || true
  else
    echo "$display_name 未安装或不可用"
  fi
}

check_cmd "Ruby" "ruby -v"
check_cmd "Rails" "rails --version"
check_cmd "Node" "node -v"
check_cmd "npm" "npm -v"
check_cmd "Yarn" "yarn -v"
check_cmd "PostgreSQL (psql)" "psql --version"


