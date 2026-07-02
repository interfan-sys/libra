#!/sur/bin/env python3


import typing
from typing import Any, Union
from abc import ABC, abstractmethod


class DataProcessor(ABC):

    def __init__(self):
        self.data = []
        self.counter = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self.data:
            raise Exception("No data to output")

        item = self.data.pop(0)
        return item

    def show_data(self) -> str:
        return (
                f"total {self.counter} items processed, "
                f"remaining {len(self.data)} on processor"
                )


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            result = []
            for item in data:
                result.append(isinstance(item, (int, float)))
            return all(result)
        else:
            return False

    def ingest(self, data: Union[int, float, list[Union[int, float]]]) -> None:
        if not self.validate(data):
            raise Exception("Improper numeric data")
        if isinstance(data, list):
            for value in data:
                self.data.append((self.counter, str(value)))
                self.counter += 1
        else:
            self.data.append((self.counter, str(data)))
            self.counter += 1

    def show_data(self) -> str:
        return "Numeric Processor: " + super().show_data()


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            result = []
            for item in data:
                result.append(isinstance(item, str))
            return all(result)
        else:
            return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise Exception("Improper text data")
        if isinstance(data, list):
            for value in data:
                self.data.append((self.counter, value))
                self.counter += 1
        else:
            self.data.append((self.counter, data))
            self.counter += 1

    def show_data(self) -> str:
        return "Text Processor: " + super().show_data()


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            for k, v in data.items():
                if not isinstance(k, str) or not isinstance(v, str):
                    return False
            return True
        elif isinstance(data, list):
            for item in data:
                if not isinstance(item, dict):
                    return False
                for k, v in item.items():
                    if not isinstance(k, str) or not isinstance(v, str):
                        return False
            return True
        return False

    def ingest(self, data: Union[dict[str, str], list[dict[str, str]]]
               ) -> None:
        if not self.validate(data):
            raise Exception("Improper log data")
        if isinstance(data, dict):
            formatted = f"{data['log_level']}: {data['log_message']}"
            self.data.append((self.counter, formatted))
            self.counter += 1
        elif isinstance(data, list):
            for item in data:
                formatted = f"{item['log_level']}: {item['log_message']}"
                self.data.append((self.counter, formatted))
                self.counter += 1

    def show_data(self) -> str:
        return "Log Processor: " + super().show_data()


class DataStream():
    def __init__(self):
        self.processor = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processor.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for item in stream:
            processed = False
            for proc in self.processor:
                if proc.validate(item):
                    proc.ingest(item)
                    processed = True
                    break
            if not processed:
                print(
                    f"Datastream Error - "
                    f"'Can't process element in stream: {item}"
                    )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if not self.processor:
            print("No processor found, no data")
            return

        for p in self.processor:
            print(p.show_data())


def main():
    print("=== Code Nexus - Data Stream ===\n")
    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()
    print()
    print("Registering Numeric Processor\n")
    stream.register_processor(NumericProcessor())
    data_stream = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead",
            },
            {
                "log_level": "INFO",
                "log_message": "User wil is connected",
            },
        ],
        42,
        ["Hi", "five"],
    ]
    print(f"Send first batch of data on stream: {data_stream}")
    stream.process_stream(data_stream)
    stream.print_processors_stats()
    print()
    print("Registering other data processors\nSend the same batch again")
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())
    stream.process_stream(data_stream)
    stream.print_processors_stats()
    print()
    print(
        "Consume some elements from the data processors: "
        "Numeric 3, Text 2, Log 1"
        )
    for i in range(3):
        stream.processor[0].output()
    for i in range(2):
        stream.processor[1].output()
    for i in range(1):
        stream.processor[2].output()
    stream.print_processors_stats()


if __name__ == "__main__":
    main()
