~/.tsugou
~/.tsugou/templates/
~/.tsugou/identities/
~/.tsugou/identities/<info>.json # contains seed|(public, private) keys, algo type, additional add-on accessible info
~/.tsugou/addons/
~/.tsugou/addons/<addon_name>/

## Client mode

init [template_name]

create [template_name] # then it will cd into it

run <script_name> # will search into $project_dir/.tsu/config.yml

commit <message> # stages all changes


### Inside a repo
get-contact <username|id> [key]


## Server mode

