def simple_generator_function():
    yield 1
    yield 2
    yield 3

for value in simple_generator_function():
    print(value)