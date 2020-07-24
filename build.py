#!/usr/bin/env python
# -*- coding: utf-8 -*-


from bincrafters import build_template_default

if __name__ == "__main__":
    builder = ConanMultiPackager()
    builder.add_common_builds()
    builder.run()