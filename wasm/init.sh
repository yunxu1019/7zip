sudo apt update
sudo apt install libatomic1
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh  # Linux/macOS
# 或 Windows: emsdk_env.bat