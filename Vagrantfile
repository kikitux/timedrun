$SCRIPT = <<-SCRIPT
which cmake gcc g++ || {
  sudo apt-get update
  sudo apt-get install -y cmake gcc g++
}
SCRIPT

Vagrant.configure(2) do |config|
  config.vm.box = "hashicorp/precise64"
  config.vm.provision "shell", inline: $SCRIPT
end
