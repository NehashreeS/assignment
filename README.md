# Assignment
# Polynomial Constant Term Calculator

## Overview

This project is a C program that reads polynomial root data from a JSON file, decodes the values from various bases to decimal, and calculates the constant term of the polynomial defined by those roots. The constant term is calculated as the product of the roots, negated.

## Features

- Reads JSON input from a specified file.
- Decodes numerical values from various bases (2, 8, 10, 12, 14, 16).
- Calculates the constant term of the polynomial based on the decoded roots.
- Outputs the constant term to the console.

## Requirements

- C compiler (e.g., `gcc`)
- `json-c` library (for JSON parsing)
