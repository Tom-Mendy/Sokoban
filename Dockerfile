FROM gcc:13.1.0 as build

WORKDIR /app

RUN useradd -u 1001 nonroot

COPY . /app

RUN make

FROM ubuntu:kinetic-20230624

WORKDIR /app

ENV GIN_MODE release

COPY --from=build /app/my_sokoban .

COPY --from=build /etc/passwd /etc/passwd

USER nonroot

ENTRYPOINT ["./my_sokoban"]

CMD ["-h"]
