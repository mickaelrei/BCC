def celsiusToFahrenheit(temp: float):
    return temp * 9/5 + 32

print("Celsius\t| Fahrenheit")
print("--------+-----------")
for i in range(0, 101, 10):
    f = celsiusToFahrenheit(i)

    print(f"{i}\t| {f}")