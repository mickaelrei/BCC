# C/5 = (F-32)/9

def fahrenheitToCelsius(temp: float):
    return (temp - 32) * 5/9

def celsiusToFahrenheit(temp: float):
    return temp * 9/5 + 32

print("Celsius\t| Fahrenheit")
print("--------+-----------")
for i in range(0, 101, 10):
    f = celsiusToFahrenheit(i)

    print(f"{i}\t| {f}")