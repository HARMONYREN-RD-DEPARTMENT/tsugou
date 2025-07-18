FROM ubuntu:latest

WORKDIR /tsugou

COPY . .

RUN apt update && apt install -y build-essential libyaml-cpp-dev libssl-dev mingw-w64

RUN make && make install

CMD ["/bin/bash"]
