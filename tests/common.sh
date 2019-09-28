# Testing helpers.

if [[ $(tput colors) -ge 8 ]]; then
  RED="$(tput setaf 1)$(tput bold)"
  GREEN="$(tput setaf 2)$(tput bold)"
  YELLOW="$(tput setaf 3)$(tput bold)"
  NONE=$(tput sgr0)
else
  RED=
  GREEN=
  YELLOW=
  NONE=
fi

passed=0
tests=0

assert_contains() {
  local name="$1"
  local input="$2"
  local expected="$3"
  echo "  ${YELLOW}Testing ${name}${NONE}"
  (( tests += 1 ))
  if [[ -x "${program}" ]]; then
    if echo ${NONL:+-n} "${input}" | "./${program}" | grep -q "${expected}"; then
      (( passed += 1 ))
      echo "    ${GREEN}✔︎${NONE} Passed"
    else
      echo "    ${RED}✘${NONE} On input '${input}', expected output to match '${expected}'"
    fi
  else
    echo "    ${RED}✘${NONE} No program ${program}"
  fi
}

assert_eq() {
  local name="$1"
  local input="$2"
  local expected="$3"
  echo "  ${YELLOW}Testing ${name}${NONE}"
  (( tests += 1 ))
  if [[ -x "${program}" ]]; then
    output=$(echo ${NONL:+-n} "${input}" | "./${program}" || true)
    if [[ "${output}" = "${expected}" ]]; then
      (( passed += 1 ))
      echo "    ${GREEN}✔︎${NONE} Passed"
    else
      echo "    ${RED}✘${NONE} On input '${input}', got '${output}', expected '${expected}'"
    fi
  else
    echo "    ${RED}✘${NONE} No program ${program}"
  fi
}

results() {
  if [[ ${passed} -ne ${tests} ]]; then
    echo "  ${RED}Failed: ${passed}/${tests} passed${NONE}"
    exit 1
  fi
  echo "  ${GREEN}Success: ${passed}/${tests} passed${NONE}"
  exit 0
}
