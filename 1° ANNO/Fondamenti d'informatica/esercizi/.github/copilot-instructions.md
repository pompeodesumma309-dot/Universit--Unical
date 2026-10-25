## Repository-specific instructions for AI coding agents

This repository currently contains small Python exercises (example: `asterischi.py`). The project is minimal: no package manifest, no tests, and no CI configs. Use the guidance below to make safe, useful edits.

Key facts
- Primary language: Python (single-file exercises).
- Example file: `asterischi.py` — reads user input, attempts to print asterisks (incomplete).
- There is no virtualenv, requirements.txt, or test runner in-repo.

What you may change
- Fix bugs and complete small functions in existing exercise files.
- Add minimal, self-contained unit tests (use the stdlib `unittest`) and a lightweight `README.md` if helpful.
- Avoid adding large frameworks or changing global project structure unless asked.

Conventions and patterns to follow
- Keep changes localized to the exercise file being edited (e.g., `asterischi.py`) and any new test file under the same directory.
- Use clear, idiomatic Python 3 code. Prefer simple scripts that run with `python asterischi.py`.
- When adding tests, name them `test_<module>.py` and place them alongside the target file.

Examples from the codebase
- `asterischi.py`: current pattern is interactive (uses `input()`), convert to a small function `build_stars(n: int) -> str` when writing tests, and keep a `if __name__ == '__main__'` block for interactive behavior.

Run / debug
- To run a single script: `python asterischi.py` (Windows PowerShell).
- To run tests after adding `unittest` tests: `python -m unittest discover -v`.

Safety and PR guidance
- Make minimal, well-documented changes. Include a short comment at top of file describing intent for non-trivial edits.
- Prefer refactors that retain original interactive behavior via an entrypoint wrapper.

If you need more
- If the user asks to scaffold a larger project (virtualenv, tests, CI), request permission first.

If anything here is unclear or you'd like additional examples (tests, refactors, or a README), ask the repository owner before making large changes.
