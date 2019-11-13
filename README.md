### Add new submodule

``` shell
git submodule add ssh://aur@aur.archlinux.org/${repo}.git ${repo}
```

### Get newest upstream.

``` shell
git submodule deinit ${repo}
git submodule init
git submodule update
git submodule foreach git pull origin master
```

### Nvchecker update

``` shell
nvchecker nvchekcer.ini
```
