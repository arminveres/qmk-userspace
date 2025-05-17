{
  description = "A basic flake with a shell";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
          # overlays = [ (self: super: { gcc-arm-embedded = super.gcc-arm-embedded-13; }) ];
        };

      in {
        devShells.default =
          pkgs.mkShell { packages = with pkgs; [ zsh qmk cppcheck clang ]; };
      });
}
