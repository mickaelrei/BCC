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

    # If doesn't exists, create file
    if (-Not (Test-Path -Path ".\$dir\$filename")) {
        Write-Host -NoNewLine "`rCreating file $filename"
        [void](New-Item -Path ".\$dir\" -Name $filename)
    }

    # Add basic text depending on extension
    if ($extension -eq ".c" -And !(Get-Content ".\$dir\$filename")) {
        "/**/`r`n`r`n#include <stdio.h>`r`n`r`nvoid main() {`r`n`r`n}" | Out-File -FilePath ".\$dir\$filename" -Encoding utf8 -Append
    } elseif ($extension -eq ".py") {
        "''''''`r`n`r`ndef main():`r`n`t...`r`n`r`n`if __name__ == `"__main__`":`r`n`tmain()" | Out-File -FilePath ".\$dir\$filename" -Encoding utf8 -Append
    }
}

# Add gitignore for .c
if ($extension -eq ".c" -And !(Test-Path -Path ".\$dir\.gitignore")) {
    [void](New-Item -Path ".\$dir\" -Name ".gitignore")

    if (!(Get-Content ".\$dir\.gitignore")) {
        "*`r`n!*.c`r`n!.gitignore" | Out-File -FilePath ".\$dir\.gitignore" -Encoding utf8 -Append
    }
}

Write-Host -NoNewLine "`r"