# Follow This Process For Cloning & Pushing

```bash
# clone this repo into a directory (name the directory something you can remember)
git clone https://github.com/haneulab/c.git ./some_directory_name

# get your own branch (ex) git checkout -b haneul-branch
git checkout -b your_branch_name-branch

# After you add files, directories and whatever content you want to contribute to the repo,
# Follow the next steps

# add to git
git add -A

# commit to git
git commit -m "Added example.txt in /intro_to_c directory (your_branch)"

# push it to the remote (github)
git push --set-upstream origin yourbranch

# AUTHENTICATION (you may need to do this when prompted upon pushing)
# username : your github username
# password : your personal generated github token
```
