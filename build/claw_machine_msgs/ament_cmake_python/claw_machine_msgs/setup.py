from setuptools import find_packages
from setuptools import setup

setup(
    name='claw_machine_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('claw_machine_msgs', 'claw_machine_msgs.*')),
)
