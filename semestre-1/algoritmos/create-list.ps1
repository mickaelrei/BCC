param ($list, $exercises, $subject = "Alg", $initials = "MR", $extension = ".py")

# Get needed parameters if not given
if ($null -eq $list) {
    $list = Read-Host -Prompt "List Number"
}

if ($null -eq $exercises) {
    $exercises = Read-Host -Prompt "Number of exercises"
}

# Dir name
if ($list -lt 10) {
    $dir = "$initials-$subject-0$list"
} else {
    $dir = "$initials-$subject-$list"
}

# Check if folder already exists
if (Test-Path -Path ".\$dir\") {
    Write-Host "Folder for this list already exists ($dir)"
    exit
}

# Create folder
[void](New-Item -Path . -Name $dir -ItemType Directory)

# Create files
for ($i = 1; $i -le $exercises; $i++) {
    if ($i -lt 10) {
        $filename = "$initials-$subject-$list-Ex-0$i$extension"
    } else {
        $filename = "$initials-$subject-$list-Ex-$i$extension"
    }
    Write-Host -NoNewLine "`rCreating file $filename"

    [void](New-Item -Path ".\$dir\" -Name $filename)
}

Write-Host -NoNewLine "`r"