FROM ros:humble-perception

# Install some dependencies packages
RUN apt update -q \
    && apt upgrade -q -y \
    && apt install -y --no-install-recommends \
    software-properties-common \
    xauth \
    vim \
    tmux \
    python3 \ 
    python3-pip \
    iproute2 \
    mosquitto \
    mosquitto-clients \
    && apt clean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
    
# Install requirements system-wide
COPY requirements.txt /tmp/
RUN pip3 install -r /tmp/requirements.txt

# copy mosquitto broker configuration file
COPY mosquitto.conf /etc/mosquitto/conf.d/
# Expose the MQTT port
EXPOSE 1883


ARG USERNAME=rosdev
ARG UID=1000
ARG GID=$UID

# Create user
RUN groupadd -g $GID $USERNAME \
    && useradd -lm -u $UID -g $USERNAME -s /bin/bash $USERNAME \
    && echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
    
    
#ENV SHELL /bin/bash    
# Switch to user   
USER $USERNAME

# use python3 installation in usr/bin
ENV PATH="/usr/bin:${PATH}"
RUN echo "export PATH=/usr/bin:\$PATH" >> /home/$USERNAME/.bashrc
RUN echo "alias python=python3" >> /home/$USERNAME/.bashrc

# Create workspace so that user own this directory
RUN mkdir -p /home/$USERNAME/ros2_ws/src
WORKDIR /home/$USERNAME/ros2_ws

# Copy configuration files
RUN echo 'source /opt/ros/'$ROS_DISTRO'/setup.bash' >> /home/$USERNAME/.bashrc \
    && echo 'source /home/'$USERNAME'/ros2_ws/install/setup.bash' >> /home/$USERNAME/.bashrc

COPY ./.tmux.conf /home/$USERNAME/
COPY ./ros_entrypoint.sh /

# Copy tmux iniatialization
COPY ./start_tmux_session.sh /home/$USERNAME/ros2_ws/

# Setup entrypoint
# Copy the entrypoint script into the image
#COPY ./entrypoint.sh /home/$USERNAME/entrypoint.sh
# Make sure the script is executable
#RUN chmod +x /home/$USERNAME/entrypoint.sh
#ENTRYPOINT ["/home/"$USERNAME"/entrypoint.sh"]

ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]
