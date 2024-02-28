from setuptools import find_packages, setup

package_name = 'keyboard_claw_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rosdev',
    maintainer_email='a.pico@posteo.de',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'keyboard_publisher = keyboard_claw_controller.keyboard_publisher:main',
            'xcarve_controller = keyboard_claw_controller.xcarve_controller:main'
        ],
    },
)
