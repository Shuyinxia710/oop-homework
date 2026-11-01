
#include "libraryresource.h"

LibraryResource::LibraryResource(string id, string n, string p)
{
    resourceId = id;
    name = n;
    publisher = p;
}

LibraryResource::~LibraryResource()
{
}

string LibraryResource::getResourceId() const
{
    return resourceId;
}

string LibraryResource::getName() const
{
    return name;
}

string LibraryResource::getPublisher() const
{
    return publisher;
}

