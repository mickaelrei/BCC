param ($list, $exercises, $subject = "Alg", $initials = "MR", $extension = ".py")

# Get needed parameters if not given
if ($null -eq $list) {
    $list = Read-Host -Prompt "List Number"
}

if ($null -eq $exercises) {
    $exercises = Read-Host -Prompt "Number of exercises"
}

if ($list -lt 10) {
    $list = "0" + $list
}

$dir = "$initials-$subject-$list"

# Check if folder already exists
if (-Not (Test-Path -Path ".\$dir\")) {
    [void](New-Item -Path . -Name $dir -ItemType Directory)
}

# Create sub folder for this extension
if (-Not (Test-Path -Path ".\$dir\$extension")) {
    [void](New-Item -Path $dir -Name $extension -ItemType Directory)
}
$dir = $dir + "\$extension"


# Create files
for ($i = 1; $i -le $exercises; $i++) {
    if ($i -lt 10) {
        $filename = "$initials-$subject-$list-Ex-0$i$extension"
    } else {
        $filename = "$initials-$subject-$list-Ex-$i$extension"
    }

    # If already exists, continue
    if (Test-Path -Path ".\$dir\$filename") {
        continue
    }

    Write-Host -NoNewLine "`rCreating file $filename"
    [void](New-Item -Path ".\$dir\" -Name $filename)

    # Add main and includes
    if ($extension -eq ".c") {
        "#include <stdio.h>`n`nvoid main() {`n`n}" | Out-File -FilePath ".\$dir\$filename"
    }
}

# Add gitignore for .c
if ($extension -eq ".c") {
    [void](New-Item -Path ".\$dir\" -Name ".gitignore")
    "*`n!*.c`n!.gitignore" | Out-File -FilePath ".\$dir\.gitignore"
}

Write-Host -NoNewLine "`r"