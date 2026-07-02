#!/sur/bin/env python3


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


def main():
    print("=== Code Nexus - Data Processor ===")
    print()
    print("Testing Numeric Porcessor...")
    numeric = NumericProcessor()
    print(f"Trying to validate input '42': {numeric.validate(42)}")
    print(f"Trying to validate imput 'Hello': {numeric.validate('Hello')}")
    try:
        print("Test invalid ingestion of string 'foo' "
              "without prior validation: ")
        numeric.ingest("foo")
    except Exception as e:
        print(f"Got Exception: {e}")
    data = [1, 2, 3, 4, 5]
    print(f"Processing data: {data}")
    for x in data:
        numeric.ingest(x)
    print("Extracting values...")
    for i in range(3):
        count, value = numeric.output()
        print(f"Numeric value {count}: {value}")
    print("Testing Text Processor...")
    text = TextProcessor()
    print(f"Trying to validate imput '42': {text.validate(42)}")
    text_data = ["Hello", "Nexus", "World"]
    print(f"Processind data: {text_data}")
    text = TextProcessor()
    text.ingest(text_data)
    print("Extracting 1 value")
    for i in range(1):
        count, value = text.output()
    print(f"Text value {count}: {value}")
    print("Testing Log Processor...")
    processor = LogProcessor()
    print(f"Trying to validate imput 'Hello': {processor.validate('Hello')}")
    log_data = [
        {"log_level": "NOTICE", "log_message": "Connection to server"},
        {"log_level": "ERR0R", "log_message": "Unauthorized access!!"}
    ]
    print(f"Processing data: {log_data}")
    print("Extracting two values...")
    processor.ingest(log_data)
    for i in range(2):
        counter, value = processor.output()
        print(f"Log entry {counter} {value}")


if __name__ == "__main__":
    main()
