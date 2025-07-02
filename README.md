# CLI_weather

**CLI_weather** is a lightweight and intuitive command-line application that lets you fetch and display real-time weather information right from your terminal. Designed for speed and simplicity, this tool is perfect for developers, system administrators, and anyone who prefers getting weather updates without leaving the command line.

## Features

- 🌦️ Real-time weather updates for any city or region
- 🧭 Simple and clean CLI output
- ⚡ Fast and efficient—minimal dependencies
- 🌍 Supports multiple locations
- 🛠️ Open source and easy to customize

## Installation

### Prerequisites

- **C Compiler** (e.g., `gcc`)
- **libcurl** (for HTTP requests)

#### Install libcurl

On **Ubuntu / Debian**:
```bash
sudo apt-get update
sudo apt-get install libcurl4-openssl-dev
```

On **Fedora / Red Hat**:
```bash
sudo dnf install libcurl-devel
```

On **macOS** (using Homebrew):
```bash
brew install curl
```

### Clone and Build

```bash
git clone https://github.com/Jayesh-Dev21/CLI_weather.git
cd CLI_weather
make
```
*Or* compile manually:
```bash
gcc main.c -o cli_weather -lcurl
```

## Usage

```bash
./weather <city>
```
**Examples:**
```bash
./weather London
./weather New York
```

## Configuration

- API keys or configuration files (if required) can be set up in the project directory.  
- Supports sandard units and custom locations.

## Contributing

Pull requests and suggestions are welcome! Please open an issue to discuss what you would like to change.

## License

This project is licensed under the MIT License.
