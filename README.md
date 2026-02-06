# Quantification_of_Mixedness

Quantification_of_Mixedness is a small toolkit to compute and analyze the "mixedness" of quantum states (or other probabilistic state representations). The project provides numerical routines to compute common mixedness measures such as purity, linear entropy, and von Neumann entropy, plus utilities to load/save states, run batch experiments, and visualize results.

> NOTE: If your project is about a different domain of "mixedness" (e.g., mixture models or image mixedness), please tell me and I will adapt this README to that domain.

## Features

- Compute purity (Tr(ρ^2)), linear entropy, and von Neumann entropy for density matrices.
- Support for pure states (state vectors) and mixed states (density matrices).
- Batch processing utilities to run experiments and export results.
- Simple plotting utilities to visualize entropy vs. parameter sweeps.
- CLI and Python API examples to get started quickly.

## Quick start

### Requirements

- Python 3.8+
- Typical dependencies:
  - numpy
  - scipy
  - matplotlib
  - (optional) qutip — if you want richer quantum utilities

Install with pip (example):

```bash
python -m pip install -r requirements.txt
# or, if there is no requirements file:
python -m pip install numpy scipy matplotlib
# optionally:
python -m pip install qutip
```

### Install / Clone

```bash
git clone https://github.com/huukhai249/Quantification_of_Mixedness.git
cd Quantification_of_Mixedness
```

## Usage

There are two primary modes: Python API and command-line.

### Python API

Example usage for computing mixedness measures from a density matrix:

```python
import numpy as np
from qom.mixedness import purity, von_neumann_entropy, linear_entropy, to_density_matrix

# Example: 2-qubit maximally mixed state
rho = np.eye(4) / 4.0

print("Purity:", purity(rho))
print("Linear entropy:", linear_entropy(rho))
print("Von Neumann entropy:", von_neumann_entropy(rho))
```

If your code provides helpers to convert a state vector to a density matrix:

```python
psi = np.array([1.0, 0.0])  # |0> state
rho = to_density_matrix(psi)
print("Purity (|0>):", purity(rho))
```

(Adjust imports and function names to match the actual module layout.)

### Command-line

If a CLI entry script (e.g., `compute_mixedness.py`) is provided:

```bash
python compute_mixedness.py --input state.npy --measure von_neumann --output result.json
```

Common CLI flags:
- `--input` : path to state vector or density matrix (NumPy `.npy` or `.npz` recommended)
- `--measure` : which measure to compute (`purity`, `linear`, `von_neumann`, `all`)
- `--output` : path to write results (JSON or CSV)
- `--plot` : generate plots

## Mixedness measures implemented

- Purity: Tr(ρ^2). Range: (1/d) .. 1 for a d-dimensional system. Purity = 1 for pure states.
- Linear entropy: S_L = 1 - Tr(ρ^2). Simple and computationally cheap.
- Von Neumann entropy: S = -Tr(ρ log ρ). A fundamental information-theoretic measure.

Numerical notes:
- Von Neumann entropy is computed using eigen-decomposition; eigenvalues are clamped (small negative values due to numerical error are set to zero) before applying the log.
- For stability use high-precision routines from numpy/scipy where necessary.

## File structure (suggested)

This is a suggested or common structure — adapt if your repository differs:

- README.md                <-- this file
- requirements.txt         <-- python dependencies
- qom/
  - __init__.py
  - mixedness.py           <-- functions: purity, linear_entropy, von_neumann_entropy, helpers
  - io.py                  <-- load/save states
  - cli.py                 <-- command-line interface
  - plots.py               <-- plotting helpers
- examples/
  - example_compute.py
  - sample_states.npy
- tests/
  - test_mixedness.py

## Examples

- Compute mixedness for a set of sample states and plot entropies:
  - `python qom/cli.py --input examples/sample_states.npy --measure all --plot`

- Quick interactive demo (Python REPL or Jupyter):
  - Load a sample state, compute measures, and display results inline.

## Testing

Run tests (pytest assumed):

```bash
pip install pytest
pytest -q
```

Tests should cover:
- Purity and entropy values for known states (pure states, maximally mixed states, Bell states).
- Numeric stability for near-pure states.

## Contributing

Contributions are welcome. Suggested workflow:

1. Fork the repository.
2. Create a feature branch: `git checkout -b feat/my-feature`
3. Add tests for your changes.
4. Open a pull request describing the change.

Please follow consistent code style (PEP8) and include unit tests for new functionality.

## License

Specify your license (e.g., MIT). If you don't have a license file yet, add one to clarify reuse terms.

## Acknowledgements & References

- Nielsen & Chuang, "Quantum Computation and Quantum Information" — for formal definitions of entropy and mixedness measures.
- qutip project for reference implementations and quantum utilities.

## Contact

If you want me to tailor this README to match your repo exactly (including correct module paths, example commands, and dependency list), share the main script or a short list of the repository files, and I will update the README accordingly.
