param ([String]$path, [Switch]$all = $false, [String]$name = "main")

if ($null -eq $path) {
    $path = Read-Host -Prompt "Project path"
}

# Check if path exists
if (!(Test-Path -Path .\$path)) {
    Write-Host "Path not found"
    exit
}

# If -all is true, compile all .cpp files
if ($all) {
    $compile_files = Get-ChildItem -Recurse -Path ".\$path" -Include "*.cpp" | Where-Object {!$_.PSIsContainer -And $_.Extension -eq ".cpp"}
    
    # If there are no files to compile, exit
    if ($compile_files.Length -eq 0) {
        Write-Host "No .cpp files to compile"
        exit
    }
} else {
    # Try to find main.cpp
    if (!(Test-Path ".\$path\main.cpp")) {
        Write-Host "main.cpp not found"
        exit
    }

    $compile_files = ".\$path\main.cpp"
}

# Add SDL2 if needed
if (!(Test-Path -Path ".\$path\SDL2.dll")) {
    Write-Host "Adding SDL2.dll"
    Copy-Item -Path "C:\SDL2\SDL2.dll" -Destination ".\$path"
}

# Call g++
g++ -I C:\SDL2\include -L C:\SDL2\lib $compile_files -o .\$path\$name -lmingw32 -lSDL2main -lSDL2

# After trying to compile, check if executable was created
if (!(Test-Path -Path ".\$path\$name") -And !(Test-Path -Path ".\$path\$name.exe")) {
    Write-Host "Error while compiling with g++: $name was not created"
    exit
}

# Prompt user to execute
$execute = Read-Host -Prompt "Execute? (y or n)"
if ($execute.ToLower() -eq "y") {
    # Get execution parameters
    $parameters = Read-Host -Prompt "Parameters"

    # Save original directory
    $original_path = Get-Location

    # Enter project directory
    Set-Location "$path"

    # Execute
    & .\$name.exe $parameters

    # Go back to original directory
    Set-Location $original_path
}

<#

TODO:
 - Mudar o nome para run-sdl.ps1
 - Adicionar um parâmetro switch opcional -compile
 - Criar uma função compile_project, que compila todos os .cpp (ou só o main.cpp se -all == false)

 - Para pegar parâmetros do usuário, pesquisar como faz pra separar por espaços
   ou como interpretar argumentos separados (ou só ficar pegando novos a cada linha fds)

#>