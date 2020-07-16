Name: linux_compat
Version: 0.1
Release: 1
Summary: support for some Linux functions in AIX
License: BSD
ExclusiveArch: ppc
ExclusiveOS: aix7.2
Source0: %{name}-%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-build
Packager: Power DevOps <https://www.power-devops.com>
BuildRequires: gcc
BuildRequires: make

%description
support for some Linux functions in AIX

%prep
%setup -q -n %{name}-%{version} -b0
rm -rf %{buildroot}

%build
make

%install
mkdir -p %{buildroot}
mkdir -p %{buildroot}/usr/lib
mkdir -p %{buildroot}/usr/include
make install DESTDIR=%{buildroot}

%files
%defattr(0644,root,root)
/usr/lib/liblinux_compat.a
/usr/include/getopt.h
/usr/include/linux_compat.h

%changelog
* Thu Jul 16 2020 info@power-devops.com
- initial release